void split_time(long total_sec, int* hr, int* min, int* sec)
{
    *hr = total_sec / 3600;
    total_sec = total_sec - *hr * 3600;
    *min = total_sec / 60;
    total_sec = total_sec - *min * 60;
    *sec = total_sec;
}
