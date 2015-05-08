#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ass/ass.h>
#include <png.h>

typedef struct image_s {
    int width, height, stride;
    unsigned char *buffer;      // RGB24
} image_t;

ASS_Library *ass_library;
ASS_Renderer *ass_renderer;

void msg_callback(int level, const char *fmt, va_list va, void *data)
{
    if (level > 6)
        return;
    printf("libass: ");
    vprintf(fmt, va);
    printf("\n");
}

static void init(int frame_w, int frame_h)
{
    ass_library = ass_library_init();
    if (!ass_library) {
        printf("ass_library_init failed!\n");
        exit(1);
    }

    ass_set_message_cb(ass_library, msg_callback, NULL);

    ass_renderer = ass_renderer_init(ass_library);
    if (!ass_renderer) {
        printf("ass_renderer_init failed!\n");
        exit(1);
    }

    ass_set_frame_size(ass_renderer, frame_w, frame_h);
    ass_set_fonts(ass_renderer, NULL, "Sans", 1, NULL, 1);
}

int main(int argc, char *argv[])
{

    if (argc < 5) {
        printf("usage: %s <video_file> <subtitle_file>\n", argv[0]);
        exit(1);
    }
    char *videofile = argv[1];
    char *subfile = argv[2];
    const int frame_w = atoi(argv[3]);
    const int frame_h = atoi(argv[4]);

    init(frame_w, frame_h);
    ASS_Track *track = ass_read_file(ass_library, subfile, NULL);
    if (!track) {
        printf("track init failed!\n");
        return 1;
    }

    char file[1000];
    sprintf(file, "gen_%s_%s.sh", videofile, subfile);
    FILE *p;
    p = fopen(file, "w");
    
    int i = 0;
    double prevous_time = 0;
    double this_time = 0;

    for (i=0;i<track->n_events;++i) {
      ASS_Event *event = track->events + i;

      char s[1000];
      int j=0;
      int ok = 0;
      while (!ok) {
        ok = 1;
        if (event->Text[j] == '{') {
          while (event->Text[j] && event->Text[j] != '}') {
            ++j;
          }
          ++j;
          ok = 0;
        }
      }
      this_time = (event->Start + event->Duration / 2) * 1.0 / 1000.0;
      prevous_time = this_time - 20;
      if (prevous_time <= 0) prevous_time = 0;

      fprintf(
        p,
        "./merge.sh %s %s %010.2lf %010.2lf %010.2lf \"%s\" %d %d\n",
        videofile,
        subfile,
        prevous_time,
        this_time - prevous_time,
        this_time,
        event->Text + j,
        frame_w,
        frame_h
      );
    }

    fclose(p);

    return 0;
}
