
#include <stdio.h>



int main(int argc, char* argv[]) {


    int keylen, index = 0;
    char* source, * dest, fBuffer[1], tBuffer[20], ckey;

    FILE* fSource, * fDest;

    source = argv[1]; // ԭ�ļ�
    dest = argv[2];   // Ŀ���ļ�

    char* key = (char*)"thisisgood";

    // ��ȡkey����
    keylen = sizeof(key);

    fSource = fopen(source, "rb");
    fDest = fopen(dest, "wb");

    while (!feof(fSource)) {

        fread(fBuffer, 1, 1, fSource);    // ��ȡ1�ֽ�

        if (!feof(fSource)) {
            ckey = key[index % keylen];     // ѭ����ȡkey
            *fBuffer = *fBuffer ^ ckey;   // xor encrypt
            fwrite(fBuffer, 1, 1, fDest); // д���ļ�
            index++;
        }

    }

    fclose(fSource);
    fclose(fDest);

}