import serial
import sys
import select

SERIAL_PORT = '/dev/ttyUSB0'

def main():
    #ser = serial.Serial(SERIAL_PORT)
    while True:
        user_input = input("Enter '1' to change temp/time, or '2' to read current temps.")
        if user_input == '1':
            new_temp = input("What temperature (Celsius) do you want?")
            new_time = input("How long should it run for (minutes)?")
        elif user_input == '2':
            TODO

if __name__ == "__main__":
    main()
