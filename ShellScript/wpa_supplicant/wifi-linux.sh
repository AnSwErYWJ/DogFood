#! /bin/sh

wpa_supplicant -B -Dnl80211 -iwlan0 -c/etc/wifi/wpa_supplicant.conf
udhcpc -i wlan0

