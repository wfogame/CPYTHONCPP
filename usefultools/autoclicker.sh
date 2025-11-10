#!/bin/bash

if pgrep -x dotool >/dev/null; then
  killall dotool
  rm -f ~/.autoclicker.pid
  notify-send "Auto-Clicker" "Stopped" -t 2000 2>/dev/null
else
  # Ask for CPS using rofi
  CPS=$(echo -e "5\n10\n20\n50\n100" | rofi -dmenu -p "Clicks Per Second:")

  if [ -z "$CPS" ]; then
    exit 0 # User cancelled
  fi

  DELAY=$(echo "scale=3; 1/$CPS" | bc)

  notify-send "Auto-Clicker" "Started at ${CPS} CPS" -t 2000 2>/dev/null
  (
    while true; do
      echo "click left"
      sleep $DELAY
    done | dotool
  ) &
  echo $! >~/.autoclicker.pid
fi
