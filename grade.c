

static int sum(int x, int y)
{


    int _global = 100;
    int z = x+y;

    return z;

}

void getGrade(int degree)
{
    sum(5,8);
    if(degree >= 85)
    {
        printf("Excellent\n");
    }
    else if(degree >= 75)
    {
        printf("Very Good\n");
    }
    else if(degree >= 65)
    {
        printf("Good\n");
    }
    else if(degree >= 55)
    {
        printf("Pass\n");
    }
    else
    {
        printf("Failed\n");
    }

}
