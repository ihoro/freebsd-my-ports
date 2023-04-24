#!/bin/sh

cd ${0%/*}
VM_HOME=$PWD
VM=portslab

_FREEBSDPORTSLAB_QEMU_MEM=${_FREEBSDPORTSLAB_QEMU_MEM:-4G}

qemu-system-aarch64 \
  --name $VM \
  -M virt \
  -accel hvf \
  -cpu host \
  -smp 8,sockets=8,cores=1,threads=1 \
  -m $_FREEBSDPORTSLAB_QEMU_MEM \
  -drive file=pflash0.img,format=raw,if=pflash,readonly=on \
  -drive file=pflash1.img,format=raw,if=pflash \
  -device virtio-gpu-pci \
  -display default,show-cursor=on \
  -device qemu-xhci \
  -device usb-kbd \
  -device usb-tablet \
  -device intel-hda \
  -device hda-duplex \
  -drive file=FreeBSD-14.0-CURRENT-arm64-aarch64.raw,format=raw,if=virtio,cache=writethrough \
  -nographic \
  -serial mon:stdio \
  --nic user,ipv6=off,model=e1000,mac=00:50:4F:52:54:53,hostfwd=tcp:127.0.0.1:3022-:22 \




######## (obsolete tip) Boot issue with nographic
# press 3 (expected to be loader prompt)
# set console=comconsole<Enter> (should see OK)
# boot<Enter>
#
# Then add the following line to /boot/loader.conf:
# console="comconsole"

