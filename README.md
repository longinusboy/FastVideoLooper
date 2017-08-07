FastVideoLooper
=====

A simple and fast video looper for Raspberry Pi, with audio support and no black screen on video rewind.

## Compiling
1. Launch your favorite linux distribution on your Raspberry
2. Install openFrameworks
3. Clone ofxOMXPlayer into openFrameworks/addons
4. Clone this repository into openFrameworks/addons/ofxOMXPlayer/FastVideoLooper
```
cd openFrameworks/addons/ofxOMXPlayer/FastVideoLooper
make
```

5. A little later you will have your FastVideoLooper in openFrameworks/addons/ofxOMXPlayer/FastVideoLooper/bin

## Installing
Copy the repository files to respective locations and make sure they have execute permissions
```
cp bin/FastVideoLooper /bin/fvl
cp fvlinit.sh /bin/
cp fvlvideoupdater.sh /bin/
chmod +x /bin/fvlinit.sh
chmod +x /bin/fvlvideoupdater.sh
```

Edit ~/.bashrc or /etc/local.rc to start fvlinit.sh at boot time

## Usage
### Compress your video
Use some utility like ffmpeg or MPEGStreamclip to compress your video with H.264 and PCM Audio (make sure to have a stereo track on the video file, even if you do not intend to have sound)

### Change Raspberry Pi Video
1. Start your Raspberry Pi
2. Copy the video.mp4 to a USB Stick
3. Connect the USB Stick on your Raspberry Pi
4. The video will update and start immediately
5. Disconnect the USB Stick

### Change volume
1. Create a file named volume.txt on your USB Stick
2. Open it on a text editor
3. Insert a value between 0 and 100 (representing the volume in percent)
4. Save and disconnect the USB Stick
5. Connect the USB Stick on your Raspberry Pi
6. The volume will be adjusted and saved for the next boot

### Change audio output
1. Create a file named audio_output.txt on your USB Stick
2. Open it on a text editor
3. Insert the value 1 to change to analog output, or any other number to HDMI output
4. Save and disconnect the USB Stick
5. Connect the USB Stick on your Raspberry Pi
6. The audio output will be changed and saved for the next boot

## Download Image
I already prepared a raspbian image specially for this purpose, with everything configured, fast boot and automatically mount every partitions as read-only.
If you just want a video looper ready to use, you can download it here:

<https://drive.google.com/file/d/0B0x7-2qLFBY3UDU0UElyaDVCZXM/view?usp=sharing>

Extract it somewhere and write the img file to a 4GB SD card or bigger, with dd or Win32DiskImager.
### Expand file system
The default size available for video is ~1.7GB, if you need more space, follow these steps:
1. Connect a keyboard to your raspbery
2. Power-on your raspberry
3. Wait until you see the prompt (If a video start playing, use the command `killall fvl` to stop it and `reset` to make terminal totally responsive again)
4. Use the next commands sequence:
```
umount /root
fdisk /dev/mmcblk0
d
3
n
p
3
3370370
(Enter)
w

partprobe
e2fsck -f /dev/mmcblk0p3
resize2fs /dev/mmcblk0p3
```
5. Reboot
