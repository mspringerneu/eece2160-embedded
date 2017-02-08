#!/bin/bash
# WiimoteConnect.sh
bluez-simple-agent hci0 8C:56:C5:3F:4C:B1
bluez-test-device trusted 8C:56:C5:3F:4C:B1 yes
bluez-test-input connect 8C:56:C5:3F:4C:B1
