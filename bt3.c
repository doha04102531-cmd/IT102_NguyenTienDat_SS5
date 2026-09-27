#include <stdio.h>

#define MAX 100

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bhyt[MAX];
    int phi_kham[MAX];
    int n = 0;

    printf("=== HE THONG KIOSK QUAN LY HANG CHO CLINIC ===\n");
    printf("Nhap so luong benh nhân ban dau (1 - %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Loi: So luong benh nhan khong hop le!\n");
        return 1;
    }


    for (int i = 0; i < n; i++) {
        printf("\n--- Nhập thong tin benh nhan thu %d (Index %d) ---\n", i + 1, i);
        ma_so[i] = 1000 + i + 1; 

     
        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);
            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("[Loi] Tuoi khong hop le. Vui long nhap lai!\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

    
        do {
            printf("Nhap trang thai BHYT (1: Co, 0: Khong): ");
            scanf("%d", &bhyt[i]);
            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("[Loi] Trang thai BHYT chi nhan gia tri 0 hoac 1. Nhap lai!\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);

    
        if (bhyt[i] == 1) {
            phi_kham[i] = 30000;
        } else {
            phi_kham[i] = 150000;
        }
    }


    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("\n=========================================================\n");
    printf("              DANH SACH HANG CHO BAN DAU                 \n");
    printf("=========================================================\n");
    for (int i = 0; i < n; i++) {
        tong_doanh_thu += phi_kham[i];
        if (tuoi[i] >= 70) {
            so_ca_uu_tien++;
            printf("MaSo: %d | Tuoi: %d (UU TIEN) | BHYT: %d | Phi: %d VND\n", 
                   ma_so[i], tuoi[i], bhyt[i], phi_kham[i]);
        } else {
            printf("MaSo: %d | Tuoi: %d | BHYT: %d | Phi: %d VND\n", 
                   ma_so[i], tuoi[i], bhyt[i], phi_kham[i]);
        }
    }
    printf("---------------------------------------------------------\n");
    printf("Tong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien (Tuoi >= 70): %d ca\n", so_ca_uu_tien);

 
    int k;
    printf("\n=========================================================\n");
    printf("               NGHIEP VU HUY LUOT KHAM                   \n");
    printf("=========================================================\n");
    printf("Nhap chi so (index) K cua benh nhan muon huy (0 den %d): ", n - 1);
    scanf("%d", &k);


    if (k < 0 || k >= n) {
        printf("[Loi] Vi tri index K khong hop le hoac vuot ngoai pham vi active!\n");
        return 1;
    }

    printf("Thong tin benh nhan bi huy: MaSo %d (Tai index %d)\n", ma_so[k], k);

 
    for (int i = k; i < n - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
        phi_kham[i] = phi_kham[i + 1];
    }
    n--; 
    
    tong_doanh_thu = 0;
    so_ca_uu_tien = 0;

    printf("\n=========================================================\n");
    printf("       DANH SACH HANG CHO SAU KHI HUY (RE-INDEXED)        \n");
    printf("=========================================================\n");
    if (n == 0) {
        printf("Hàng chờ hiện tại đang rỗng!\n");
    } else {
        for (int i = 0; i < n; i++) {
            tong_doanh_thu += phi_kham[i];
            if (tuoi[i] >= 70) {
                so_ca_uu_tien++;
                printf("Index %d -> MaSo: %d | Tuoi: %d (UU TIEN) | BHYT: %d | Phi: %d VND\n", 
                       i, ma_so[i], tuoi[i], bhyt[i], phi_kham[i]);
            } else {
                printf("Index %d -> MaSo: %d | Tuoi: %d | BHYT: %d | Phi: %d VND\n", 
                       i, ma_so[i], tuoi[i], bhyt[i], phi_kham[i]);
            }
        }
    }
    printf("---------------------------------------------------------\n");
    printf("Tong doanh thu cap nhat thuc te: %d VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien con lai: %d ca\n", so_ca_uu_tien);
    printf("=========================================================\n");

    return 0;
}