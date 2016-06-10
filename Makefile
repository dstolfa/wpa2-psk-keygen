all: wpa2-psk-keygen

wpa2-psk-keygen: main.c
	cc main.c -fstack-protector -O2 -Wall -Wextra -pedantic -fPIE -o wpa2-psk-keygen

clean:
	rm wpa2-psk-keygen

install:
	cp wpa2-psk-keygen /usr/local/bin/

uninstall:
	rm /usr/local/bin/wpa2-psk-keygen
