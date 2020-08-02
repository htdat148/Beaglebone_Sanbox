# Compile and load device tree overlay for BBB

This is an instruction to compile device and load overlay files for kernel 4.1x.

Uboot has taken care of the overlays.
## Compile the device tree files

Open build.sh, add the files name need to be compiled, then run
```bash
sudo ./build.sh
```

## Usage
Copy the .dtbo file to /lib/firmware/ so when the board is booting, it can find these overlays
```bash
cp overlay_name.dtbo /lib/firmware/
```

## Add appropriate line in the /boot/uEnv.txt
For my overlay files, I will add 4 files.

Be careful when add directory for overlay, the booting process can be hang if you put wrong directory
```bash
uboot_overlay_addr4=/lib/firmware/BB-PWM0-00A0.dtbo
uboot_overlay_addr5=/lib/firmware/BB-PWM1-00A0.dtbo
uboot_overlay_addr6=/lib/firmware/BB-PWM2-00A0.dtbo
uboot_overlay_addr7=/lib/firmware/PB-PWM-RGB-TECHLAB-CAPE.dtbo
```
Reboot and check these files already applied or not in /proc/device-tree/chosen/overlays/


# Addition information
[bb.org-overlay](https://github.com/beagleboard/bb.org-overlays)

[Derek Monlley](http://derekmolloy.ie/gpios-on-the-beaglebone-black-using-device-tree-overlays/)