# Questions

## What's `stdint.h`?

A header file that contains typedefs

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To standardize the size of certain data types across multiple platforms.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is 1 byte, a DWORD is 4 bytes, a LONG is 4 bytes, and a WORD is 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
BM


## What's the difference between `bfSize` and `biSize`?

bf refers to the image file's  header/metadata whereas bi is referring to attribute of the actual image.

## What does it mean if `biHeight` is negative?

It means that the image starts with the bottom pixels vs the top pixels first.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Because it is looking to a pointer, if there is no value there (or a NULL value), it returns instead of suffering a segmentation fault.

## Why is the third argument to `fread` always `1` in our code?

Because fread is reading the size of the entire structure and told to treat it as a single element.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

fseek moves the file pointer to a specified postion. In this program, we tell it to skip over the padding of the image.

## What is `SEEK_CUR`?

SEEK_CUR specifies that the file pointer should be moved to the given position, rather than the beginning or end of the file.
