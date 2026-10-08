#include <stdio.h>
struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int actual_fee;
};
int main() {
    struct UserAccount user_list[100];
    int n;
    int i;
    int total_revenue = 0;
    int downgraded_count = 0;
    int penalty;
    do {
        printf("Nhap so luong tai khoan (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("So luong khong hop le, vui long nhap lai!\n");
        }
    } while (n < 1 || n > 100);
    for (i = 0; i < n; i++) {
        printf("\nNhap tai khoan %d:\n", i + 1);
        printf("Ma tai khoan: ");
        scanf("%d", &user_list[i].user_id);
        printf("Ten tai khoan: ");
        scanf("%49s", user_list[i].username);
        do {
            printf("Loai goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &user_list[i].plan_type);
            if (user_list[i].plan_type < 1 || user_list[i].plan_type > 3) {
                printf("Loai goi khong hop le, vui long nhap lai!\n");
            }
        } while (user_list[i].plan_type < 1 || user_list[i].plan_type > 3);
        do {
            printf("So ngay no cuoc: ");
            scanf("%d", &user_list[i].days_overdue);

            if (user_list[i].days_overdue < 0) {
                printf("So ngay no khong duoc am, vui long nhap lai!\n");
            }
        } while (user_list[i].days_overdue < 0);
        do {
            printf("So thiet bi dang ket noi: ");
            scanf("%d", &user_list[i].active_devices);

            if (user_list[i].active_devices < 0) {
                printf("So thiet bi khong duoc am, vui long nhap lai!\n");
            }
        } while (user_list[i].active_devices < 0);
    }
    for (i = 0; i < n; i++) {
        user_list[i].actual_fee = 0;
        if (user_list[i].days_overdue >= 3) {
            user_list[i].plan_type = 1;
            user_list[i].actual_fee = 0;
            downgraded_count++;
        }
        if (user_list[i].plan_type == 1) {
            user_list[i].actual_fee = 0;
        } else if (user_list[i].plan_type == 2) {
            user_list[i].actual_fee = 120000;
            if (user_list[i].active_devices > 1) {
                penalty = (user_list[i].active_devices - 1) * 30000;
                user_list[i].actual_fee += penalty;
            }
        } else if (user_list[i].plan_type == 3) {
            user_list[i].actual_fee = 250000;
        }
        total_revenue += user_list[i].actual_fee;
    }
    printf("\n=== BAO CAO RA SOAT TAI KHOAN ===\n");
    printf("%-10s %-20s %-10s %-12s %-12s %-20s\n",
           "Ma TK", "Ten TK", "Ma Goi", "Thiet Bi", "No Cuoc", "Phi Thuc Thu");
    printf("-------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d %-12d %-12d %-20d\n",
               user_list[i].user_id,
               user_list[i].username,
               user_list[i].plan_type,
               user_list[i].active_devices,
               user_list[i].days_overdue,
               user_list[i].actual_fee);
    }
    printf("-------------------------------------------------------------------------------\n");
    printf("Tong doanh thu thuc te: %d VND\n", total_revenue);
    printf("Tong so tai khoan bi ha cap ve Free: %d\n", downgraded_count);
    return 0;
}
