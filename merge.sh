#/bin/bash
# Usage: ./script <video_file> <subtitle_file> <second> <subtitle> <width> <height>

mkv_source=$1
subtitle_source=$2
lastsecond=$3
duration=$4
second=$5
subtitle=$6
width=$7
height=$8
subtitle_png=$subtitle_source".png"
raw_png=$mkv_source"raw.png"

./genpng ${subtitle_png} ${subtitle_source} ${second} ${width} ${height}
avconv -ss ${lastsecond} -i ${mkv_source} -ss ${duration} ${raw_png}
convert ${raw_png} ${subtitle_png} -composite -format jpg -quality 90 "${second}.jpg"
