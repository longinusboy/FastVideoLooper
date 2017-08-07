#!/bin/bash

if [ "`tty`" == "/dev/tty1" ]; then
  /bin/fvlvideoupdater.sh >/dev/null 2>/dev/null &
  mount -o ro /dev/mmcblk0p3 /root/
  if [ -f /root/video.mp4 ]; then
    /bin/fvl
  fi
fi
