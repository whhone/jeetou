## Introduction
This is the tool building the screenshots behind 截圖道(jeetou.com). It generates one screenshot every subtitle in a given MKV video. 

## Requirements

### Install the required packages
####Ubuntu:
```
sudo apt-get install libav-tools libpng12-dev libass-dev
```

####OSX:
```
brew install libav libass 
```

### Build
```
make all
```

## Usage
### 0) Understand the mkv file and select the subtitle
mkv is a container of audio, video and subtitle. It could contains multiple subtitle of different languages. The first thing to do is to select the desired subtitle.
```
mkvinfo <mkvfile>
```

### 1) Generate ALL screenshot
```
jeetou <<mkvfile>> <subtitle_track>
```
