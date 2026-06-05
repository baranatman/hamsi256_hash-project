# Hamsi-256 Hash Project

## Proje Hakkında

Bu proje, Hamsi hash algoritmasını kullanarak Linux komut satırında çalışan bir dosya bütünlüğü doğrulama uygulamasıdır.

Proje C dili ile geliştirilmiş olup dosyaları belirli sayıda parçalara bölerek her parça için ayrı hash değeri üretebilmektedir.

## Özellikler

- Hamsi-256 ve Hamsi-512 desteği
- Dosya bölme (Split)
- Hexadecimal çıktı üretimi
- Linux komut satırı desteği
- Veri bütünlüğü doğrulama

## Kullanılan Teknolojiler

- C Programlama Dili
- GCC
- MSYS2
- Linux Command Line
- SPHlib

## Derleme

```bash
gcc ana.c sph_hamsi.c -o sha3zoohash.out
```

## Kullanım

```bash
./sha3zoohash.out -size 512 -split 2 test.txt
```

## Örnek Çalıştırma

test.txt içeriği:

```text
HelloHello
```

Komut:

```bash
./sha3zoohash.out -size 512 -split 2 test.txt
```

Çıktı:

```text
5510c36b3089...
5510c36b3089...
```

İki çıktı aynı olduğu için split işleminin doğru çalıştığı görülmektedir.

## Not

Bu projede yeni bir hash algoritması geliştirilmemiştir. Mevcut Hamsi algoritması kullanılarak Linux komut satırında çalışan bir hash uygulaması geliştirilmiştir.

## Hazırlayan

Muhammed Baran Atmanoğlu

OSTİM Teknik Üniversitesi

Bilişim Güvenliği Teknolojisi
