char buf[1 << 15], *phead = buf, *ptail = buf;
#define getchar() (phead==ptail&&(ptail=(phead=buf)+fread(buf,1,1<<15,stdin)),phead==ptail?0:*phead++)
template<typename T>
inline T read() {
    char c = getchar();
    bool f = true;
    T var = 0;
    while(c < '0' || '9' < c) c = getchar();
    if(c == '-') f = false, c = getchar();
    while('0' <= c && c <= '9') var = var * 10 + c - '0', c = getchar();
    return f ? var : -var;
}
