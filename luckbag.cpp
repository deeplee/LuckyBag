/*
* =====================================================================================
*
*       Filename:  luckbag.cpp
*
*    Description:  a function like wechat luckbag
*
*        Version:  1.0
*        Created:  2016年01月14日 16时18分29秒
*
*         Author:  Deep Lee
*
* =====================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <sys/time.h>

namespace LuckBag {

    long gettime()
    {
        struct timeval nowtime;
        struct timezone tz;
        gettimeofday(&nowtime, &tz);
        return (nowtime.tv_sec*1000000 + nowtime.tv_usec);
    }

    /* 随机获取当前红包数值*/
    double getMoney(double moneyTotal)
    {
        int randMoney = 0;
        double money = 0.0;
        unsigned int tmpSum = 0;
        double tmpMoney = 0.0;
        srand(gettime());

        tmpMoney = (double)(rand() % (int)(moneyTotal*100))/100 ;
        tmpSum = (int) (tmpMoney / moneyTotal);
        money = tmpMoney - moneyTotal*tmpSum;
        // printf("%.2f, %.2f, %d, %.2f\n",moneyTotal, tmpMoney, tmpSum, money);
        return money + 0.01;
    }

    void getLuckBag(double moneySum, unsigned int bagNum)
    {
        double moneyMin = 0.01f;
        double money = 0.0;
        double moneyTotal = moneySum;
        for(int i = 0; i < bagNum - 1; i++) {
            //保证剩下的没人最少获取0.01
            money = getMoney(moneyTotal - moneyMin * (bagNum-1-i));
            moneyTotal = moneyTotal - money;
            printf("The %d redbag money is %.2f\n", i+1, money);
        }
        printf("The %d redbag money is %.2f\n", bagNum, moneyTotal);
    }

}

int main(int argc, char **argv)
{
    LuckBag::getLuckBag(60, 10);
}

