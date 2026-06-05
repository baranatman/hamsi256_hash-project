# Hamsi-256 Hash Project

## Proje Hakkında

Bu proje, mevcut Hamsi hash algoritmasını kullanarak Linux komut satırında çalışan bir dosya bütünlüğü doğrulama uygulamasıdır.

Proje C dili ile geliştirilmiştir. Uygulama, verilen bir dosyayı `-split` parametresine göre belirli sayıda parçaya böler ve her parça için ayrı hash değeri üretir.

Bu projede yeni bir hash algoritması geliştirilmemiştir. Mevcut Hamsi algoritması kullanılarak komut satırı tabanlı bir hash uygulaması hazırlanmıştır.

## Özellikler

- Hamsi-256 ve Hamsi-512 desteği
- Dosya Bölme (Split)
- Her parça için ayrı hash üretimi
- Hexadecimal çıktı üretimi
- Linux komut satırı desteği
- Veri bütünlüğü doğrulama

## Kullanılan Teknolojiler

- C Programlama Dili
- GCC Derleyicisi
- MSYS2
- Linux Komut Satırı
- SPHlib Hamsi Implementasyonu

## Proje Dosyaları

- `ana.c` : Komut satırı parametrelerini alan ve split işlemini yöneten ana program dosyası
- `sph_hamsi.c` : Hamsi hash algoritmasının kaynak kodu
- `sph_hamsi.h` : Hamsi algoritması için başlık dosyası
- `sph_hamsi_helper.c` : Yardımcı fonksiyonlar ve tablolar
- `sph_types.h` : SPHlib veri tipi tanımları
- `test.txt` : Örnek test dosyası

## Derleme

```bash
gcc ana.c sph_hamsi.c -o sha3zoohash.out
```

## Kullanım

```bash
./sha3zoohash.out -size 512 -split 2 test.txt
```

## Parametreler

- `-size` : Hash uzunluğunu belirtir. 256 veya 512 değeri kullanılabilir.
- `-split` : Dosyanın kaç parçaya bölüneceğini belirtir.
- `test.txt` : Hash değeri hesaplanacak girdi dosyasıdır.

## Örnek Çalıştırma

test.txt dosyası içeriği:

```text
HelloHello
```

Komut:

```bash
./sha3zoohash.out -size 512 -split 2 test.txt
```

Çıktı:

```text
5510c36b3089b6ce02778e937c260b6eee544c15e61e1e94345b80cee68fe5afdef9ee0c739c9be8f0ac99c0f28f7e1e9950cf21415b23f14fce9185c2b7a15a
5510c36b3089b6ce02778e937c260b6eee544c15e61e1e94345b80cee68fe5afdef9ee0c739c9be8f0ac99c0f28f7e1e9950cf21415b23f14fce9185c2b7a15a
```

Bu örnekte HelloHello içeriği iki eşit parçaya ayrılmıştır. Her iki parça da aynı veriyi içerdiği için üretilen hash değerleri aynıdır. Bu durum split mekanizmasının doğru çalıştığını göstermektedir.

## Projenin Amacı

Bu projenin amacı kriptografik hash fonksiyonlarının çalışma mantığını uygulamalı olarak öğrenmek, dosya bütünlüğü doğrulama işlemlerini gerçekleştirmek ve Linux komut satırında çalışan bir hash uygulaması geliştirmektir.

## Akademik Kapsam

Bu çalışma OSTİM Teknik Üniversitesi Bilişim Güvenliği Teknolojisi bölümü Kriptoloji dersi kapsamında gerçekleştirilmiştir.

Projede Hamsi hash algoritması kullanılarak dosya bütünlüğü doğrulama, hash üretimi ve dosya bölme (split) işlemleri gerçekleştirilmiştir.

## Hazırlayan

Muhammed Baran Atmanoğlu

OSTİM Teknik Üniversitesi

Bilişim Güvenliği Teknolojisi
