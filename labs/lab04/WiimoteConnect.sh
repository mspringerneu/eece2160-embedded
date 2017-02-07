#!/bin/bash
# WiimoteConnect.sh
bluez-simple-agent hci0 XX:XX:XX:XX:XX:XX
bluez-test-device trusted XX:XX:XX:XX:XX:XX yes
bluez-test-input connect XX:XX:XX:XX:XX:XX
