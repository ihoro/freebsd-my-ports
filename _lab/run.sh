#!/bin/sh

cd ${0%/*}
VM_HOME=$PWD
VM_NAME=portslab
VM_MEM=4G
VM_MAC=aa:bb:cc:01:02:03
VM_SSH_PORT=3022

QEMU_PREFIX=""
QEMU_PARAMS=""

# TODO: for now the order is very important
test -f ./d1_usrports.qcow2 && QEMU_PARAMS="${QEMU_PARAMS} -drive file=d1_usrports.qcow2,if=virtio,cache=writethrough "

$QEMU_PREFIX \
qemu-system-aarch64 \
  --name $VM_NAME \
  -M virt \
  -accel hvf \
  -cpu host \
  -smp 8,sockets=8,cores=1,threads=1 \
  -m $VM_MEM \
  -device virtio-gpu-pci \
  -display default,show-cursor=on \
  -device qemu-xhci \
  -device usb-kbd \
  -device usb-tablet \
  -device intel-hda \
  -device hda-duplex \
  -nographic \
  -serial mon:stdio \
  -drive file=/opt/homebrew/opt/qemu/share/qemu/edk2-aarch64-code.fd,if=pflash,format=raw,readonly=on \
  -drive file=d0_root.qcow2,if=virtio,cache=writethrough \
  --nic user,ipv6=off,model=e1000,mac=${VM_MAC},hostfwd=tcp:127.0.0.1:${VM_SSH_PORT}-:22 \
  ${QEMU_PARAMS}




######## (obsolete tip) Boot issue with nographic
# press 3 (expected to be loader prompt)
# set console=comconsole<Enter> (should see OK)
# boot<Enter>
#
# Then add the following line to /boot/loader.conf:
# console="comconsole"

