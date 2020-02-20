/*************************************************************************
	> File Name: bin2obj.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 23 Jul 2019 03:59:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <elf.h>

/*************************************************************************
$ gcc -c bin2obj.c -o bin2obj.o # check format and architecture
$ objcopy -I binary -O elf64-x86-64 -B i386:x86-64 nhxc.wav audio.o
$ objdump -x audio.o
$ gcc -c bin2obj.c -o bin2obj.o
$ g++ bin2obj.o audio.o -o bin2obj
$ ./bin2obj
 ************************************************************************/


extern _binary_nhxc_wav_start;
extern _binary_nhxc_wav_end;
extern _binary_nhxc_wav_size;

int main() {
	printf("binary to object:\n");
    
	printf("elf head: %ld\n", sizeof(Elf64_Ehdr));
    printf("_binary_nhxc_wav_size: %p\n_binary_nhxc_wav_end: %p\n_binary_nhxc_wav_size: %p\n", &_binary_nhxc_wav_start, &_binary_nhxc_wav_end,  &_binary_nhxc_wav_size);

    unsigned char * audio_buf = (unsigned char *)&_binary_nhxc_wav_start;
    unsigned long size = (unsigned long)&_binary_nhxc_wav_size;

	FILE *fp = fopen("./out.wav", "wb");
	if (!fp) {
		fprintf(stderr, "fopen failed!\n");
		return -1;
	}

	fwrite(audio_buf, size, 1, fp);

	fclose(fp);

	return 0;
}