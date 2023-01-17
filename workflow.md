# Ako začať s crypto shield

0. Arduino IDE
1. Zisti si softvérovú architekturú
    - v tomto prípade pre Arduino UNO je to AVR
2. Vyznaj sa v obvodoch a I2C
3. Získaj knižnice komunikaciu s ATSHA204 a ATECC108
    - https://github.com/cryptotronix/cryptoauth-arduino.github
4. Adresy IC, lebo nikde neboli
    - ATECC108 I2C adresa 0xc0
    - ATSHA204 I2C adresa 0xc8
    - ako komunikovať I2C s boardom?
