/*
 * Simple Timer (no pic):
 * 00:00:00
 * this is vary stupid!! No efficiency at all!!
 */

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
using namespace std;

#define SEPARATOR ':'
#define H_MAX 24
#define M_S_MAX 60
#define DUL 10

class Timer {
public:
    Timer(): h(0),m(0),s(0) {}
    void run();
private:
    int h; //hour
    int m; //minute
    int s; //second
    void h_add() { h++; h%=H_MAX; }
    void m_add() { int c=(++m)/M_S_MAX; m%=M_S_MAX; if(c) { h_add();} }
    void s_add() { int c=(++s)/M_S_MAX; s%=M_S_MAX; if(c) { m_add();} }
    void pt() { //print timer
        cout << "TIME IS MONEY:" << endl;
        if (h<DUL) cout << 0;
        cout << h; cout << SEPARATOR;
        if (m<DUL) cout << 0;
        cout << m; cout << SEPARATOR;
        if (s<DUL) cout << 0;
        cout << s;
        cout << endl;
    }
};

void Timer::run()
{
    struct timeval prev, next;
    gettimeofday(&prev, NULL);
    while (1) {
        gettimeofday(&next, NULL);
        if (next.tv_sec - prev.tv_sec == 1) {
            prev = next;
            s_add();
            system("clear");
            pt();
            usleep(500);
        }
    }
}

int main()
{
    Timer t;
    t.run();

    return 0;
}
