## Introduction
This is the tool building the screenshots behind <a href="http://jeetou.com/" target="_blank">截圖道 (jeetou.com)</a>. Given a MKV video, it generates screenshots for every subtitle.  

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
mkv is a container of audio, video and subtitle. It could contains multiple subtitle of different languages. The first thing to do is to find the desired subtitle.
```
mkvinfo <mkvfile>
```

### 1) Generate ALL screenshot
```
jeetou <<mkvfile>> <subtitle_track>
```

## How it works?
### Step 1: Generate the subtitle image
![Image of sameple 1]
(http://whhone.com/wp-content/uploads/2013/08/subtitle.png)

### Step 2: Take the screenshot from the video
![Image of sameple 1]
(http://whhone.com/wp-content/uploads/2013/08/raw.png)

### Step 3: Combine the above two images
![Image of sameple 1]
(http://whhone.com/wp-content/uploads/2013/08/combine.jpg)

`jeetou` extracts the subtitle file and repeats the above three steps for each subtitle.
