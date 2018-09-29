#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char student_ID[5];
    char name_of_student[20];
    char phone_number_of_student[11];
} sinhVien;

void themSinhVienMoi(int *p, sinhVien sinhVienArray[]) {
    char thongTinSinhVien[10];
    for (int i = 0; i < 10; ++i) {
        while (1 == 1) {
            printf("Vui lòng nhập mã sinh viên thứ %d: \n", *p + 1);
            scanf("%s", sinhVienArray[*p].student_ID);
            if (strlen(sinhVienArray[*p].student_ID) != 5) {
                printf("Mã sinh viên phải đủ 5 kí tự! Vui lòng nhập lại sinh viên thứ %d. \n", *p + 1);
            } else {
                break;
            }
        }
        printf("Vui lòng nhập tên sinh viên thứ %d: \n", *p + 1);
        fgetc(stdin);
        fgets(sinhVienArray[*p].name_of_student, 10, stdin);
        printf("Nhập số điện thoại sinh viên thứ %d:\n", *p + 1);
        fgetc(stdin);
        scanf("%[0-9]", sinhVienArray[*p].phone_number_of_student);
        *p++;
        printf("Vui lòng nhập exit để dừng hoặc ấn Enter để tiếp tục. \n");
        fgetc(stdin);
        fgets(thongTinSinhVien, 10, stdin);
        if (strcmp(thongTinSinhVien, "exit\n") == 0) {
            break;
        }
        if (*p == 10) {
            printf("Danh sách sinh viên đã đầy.");
            break;
        }
    }
}

void hienThiSinhVien(sinhVien sinhVienArray[]) {
    int i = 0;
    printf("-%-25s|%-25s|%s", "Mã sinh viên", "Tên sinh viên", "Điện thoại");
    for (int j = 0; j < 10; ++j) {
        printf("\n-%-23s|%-23s|%s", sinhVienArray[i].student_ID, sinhVienArray[i].name_of_student,
               sinhVienArray[i].phone_number_of_student);
        i++;
    }
}

void luuDanhSachSinhVien(sinhVien sinhVienArray[]) {
    int i = 0;
    FILE *fp = fopen("danhsachsinhvien.txt", "w+");
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for (int j = 0; j < 10; ++j) {
        fprintf(fp, "\n-%-18s|%-18s|%s", sinhVienArray[i].student_ID, sinhVienArray[i].name_of_student,
                sinhVienArray[i].phone_number_of_student);
        i++;
    }
    fclose(fp);
}

void docDanhSachSinhVien() {
    FILE *fp;
    printf("_______Đọc dữ liệu từ file______\n");
    fp = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 255;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

int menu() {
    int menuchoice;
    printf("\n_ _ _ _ _ _ MENU _ _ _ _ _ _\n");
    printf("\n                            \n");
    printf("1. Thêm sinh viên mới.\n");
    printf("2. Hiển thị danh sách sinh viên.\n");
    printf("3. Lưu danh sách sinh viên ra file.\n");
    printf("4. Đọc danh sách sinh viên từ file.\n");
    printf("5. Thoát chương trình.\n");
    printf("Vui lòng nhập lựa chọn của bạn (1-5): \n");
    scanf("%d", &menuchoice);
    return menuchoice;
}

int main() {
    int *p, i = 0, choice;
    p = &i;
    sinhVien sinhVienArray[10] = {};
    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Thêm sinh viên mới. \n");
                themSinhVienMoi(p, sinhVienArray);
                break;
            case 2:
                printf("Danh sách sinh viên. \n");
                hienThiSinhVien(sinhVienArray);
                break;
            case 3:
                luuDanhSachSinhVien(sinhVienArray);
                printf("Đã lưu danh sách sinh viên vào file danhsachsinvien.txt\n");
                break;
            case 4:
                docDanhSachSinhVien();
                break;
            case 5:
                printf("Hẹn gặp lại!");
                break;
            default:
                printf("Lựa chọn của bạn sai. Vui lòng chọn lại từ 1 đến 5.");
        }
    } while (choice != 6);
    return 0;
}
