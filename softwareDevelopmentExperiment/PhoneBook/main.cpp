void write_bitFile(const char *FILE_RD, const char *FILE_WR, HNode *HT, HCode *HC, int n)
{
    FILE *stream_rd, *stream_wr;
    size_t num_read, num_written;
    int rw_cnt = 0;
    long long offsetRD = 0;
    long long offsetWR = 0;
    unsigned char *bufRD = new unsigned char[WR_SIZE];
    if (0 != fopen_s(&stream_wr, FILE_WR, "wb"))
    { //获取待写入文件的句柄
        return;
    }

    unsigned char *bufRD = new unsigned char[WR_SIZE];

    unsigned char *bufWR = new unsigned char[WR_SIZE];
    unsigned char *buf = new unsigned char[8 * WR_SIZE + 1];
    if (0 == fopen_s(&stream_rd, FILE_RD, "rb"))
    {
        long long fileSize = getFileSize(FILE_RD);
        int k = 0;
        while (!feof(stream_rd))
        {
            //读
            num_read = fread(bufRD, sizeof(char), WR_SIZE, stream_rd);
            if (displayLoading == 1 && 0 != num_read)
            {
                system("cls");
                long long curpoision = _ftelli64(stream_rd); //得到当前加载位置
                double percent = curpoision / fileSize * 100;
                cout << "Encoding perccent: " << percent << "% " << endl;
            }
            if (0 == num_read)
                break;
            offsetRD = num_read;                      //文件偏移
            _fseeki64(stream_rd, offsetRD, SEEK_CUR); //注意，这样做不能随意更改文件流位置
            //文件读出后放入新buf区
            long long maxn = num_read;
            for (int i = 0; i < maxn; i++) //内存字段扫描，每次1B
            {
                for (int j = HC[bufRD[i]].start; j < n; j++) //编码扫描
                {
                    //取出编码信息，
                    unsigned char tempchar1bit = HC[bufRD[i]].bit[j] + '0';
                    buf[k++] = tempchar1bit;

                    if (k = 8 * WR_SIZE) //装满了，但是可能j还有信息
                    {
                        buf[k] = '\0';
                        char2b(buf, bufWR); //把信息转换后存到bufWR
                        k = 0;
                        num_written = fwrite(bufWR, sizeof(char), WR_SIZE, stream_wr);
                        offsetWR = num_written;
                        _fseeki64(stream_wr, offsetWR, SEEK_CUR);
                        buf[0] = '\0';
                    }
                }
            }
            if (buf[0] != '\0') //说明读完了但是buf区还有东西
            {
                int tempi=((k-1)%8+1);
                if( (tempi !=8)
                {
                    for(int kk=0;kk<8-tempi;kk++)
                    buf[k++]=0;
                }
                buf[k] = '\0';
                char2b(buf, bufWR); //把信息转换后存到bufWR
                k = 0;
                num_written = fwrite(bufWR, sizeof(char), WR_SIZE, stream_wr);
                offsetWR = num_written;
                _fseeki64(stream_wr, offsetWR, SEEK_CUR);
                buf[0] = '\0';
            }
        }
    }

    //资源释放
    delete[] bufRD;
    fclose(stream_rd);
    fclose(stream_wr);
}