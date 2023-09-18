/* 使用联合类型 */
/* 制作一个汽车信息管理程序，汽车有两种状态，一种是属于公司，一种是属于个人，属于公司的汽车机构体要包含公司的名称，属于个人的汽车要包含个人的身份证ID */
#include <stdio.h>
union car_data {
    int ID;
    char company_name[30];
};

struct car {
    union car_data ownership;
    int status; // 表明汽车属于公司还是个人
    double price;
};

void printCar(struct car* mycar) {

    printf("Your car value %f$\n", mycar->price);
    
    if (mycar->status == 1) {
        printf("Your car belongs to %s\n", mycar->ownership.company_name);
    } else {
        printf("The ID of the owner is %d\n", mycar->ownership.ID);
    }
}

int main() {
    struct car mycar;

    printf("Input the information of your car.\n");
    printf("Is it belongs to personal or company?(1 = company, 0 = personal)\n");
    while (scanf("%d", &mycar.status) != 1 && mycar.status != 0) {
        printf("You need to input the number between 0 and 1. Now try again.\n");
    }

    if (mycar.status == 1) {
        // car belongs to company
        printf("Input the name of your company.\n");
        scanf("%s", mycar.ownership.company_name);
    } else {
        // car is personal
        printf("Input the ID of owner.\n");
        scanf("%d", &mycar.ownership.ID);
    }

    printf("Input the price of the car.\n");
    scanf("%lf", &mycar.price);

    printCar(&mycar);
}