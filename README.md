## Requirements

Ubuntu:
sudo apt-get install libav-tools libpng12-dev libass-dev

OSX:
brew install libav libass 

## Usage
### 0 Understand the mkv file and select the subtitle
mkv is a container of audio, video and subtitle. It could contains multiple subtitle of different languages. The first thing to do is to select the desired subtitle.
mkvinfo <mkvfile>

### 1 Generate ALL screenshot
  jeetou <mkvfile> <subtitle_track>