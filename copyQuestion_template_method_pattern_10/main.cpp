#include "testpaper.h"

int main(int argc, char *argv[])
{
    TestPaper *a = new TestPaper1();
    a->question1();
    a->question2();
    delete a;
    a = new TestPaper2();
    a->question1();
    a->question2();
    return 0;
}
