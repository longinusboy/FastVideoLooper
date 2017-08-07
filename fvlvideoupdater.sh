#!/bin/bash

lastinserted=true
while true; do
  if [ -b "/dev/sda1" ] && ! $lastinserted; then
    lastinserted=true
    mount -o ro /dev/sda1 /mnt
    if [ $? -eq 0 ]; then
      mount -o remount,rw /root
      mount -o remount,rw /boot
      killall fvl
      cp /mnt/video.mp4 /root/ 2> /dev/null
      cp /mnt/volume.txt /boot/ 2> /dev/null
      cp /mnt/audio_output.txt /boot/ 2> /dev/null
      umount /mnt
      mount -o remount,ro /boot
      mount -o remount,ro /root
      if [ -f /root/video.mp4 ]; then
        /bin/fvl
      fi
    fi
  else
    if [ ! -b "/dev/sda1" ]; then
      lastinserted=false;
    fi
  fi
  sleep 10
done
exit 0
