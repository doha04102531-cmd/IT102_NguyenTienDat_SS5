#include <stdio.h>

int main() {

    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    int phi_kham[4];

 
    printf("=== NHAP DU LIEU TIEP NHAN 4 BENH NHAN ===\n");
    for (int i = 0; i < 4; i++) {
        printf("--- Benh nhan thu %d ---\n", i + 1);
        printf("Nhap tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);
        printf("Nhap trang thai BHYT (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);
    }

    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;


    printf("\n=========================================\n");
    printf("      BANG KET QUA XU LY VA PHAN LUONG   \n");
    printf("=========================================\n");

    for (int i = 0; i < 4; i++) {
        int tuoi = tuoi_benh_nhan[i];
        int bhyt = co_bao_hiem[i];

   
        if (bhyt != 0 && bhyt != 1) {
            bhyt = 0;
            co_bao_hiem[i] = 0; 
        }

    
        if (tuoi <= 0 || tuoi > 120) {
            phi_kham[i] = 0;
            printf("Benh nhan %d | Tuoi: %d (LOI DU LIEU) | BHYT: %d | Phi: 0 VND | Luong: LOI DU LIEU\n", 
                   i + 1, tuoi, bhyt);
        } else {

            if (bhyt == 1) {
                phi_kham[i] = 40000;
            } else {
                phi_kham[i] = 200000;
            }

            tong_doanh_thu += phi_kham[i];

            if (tuoi > 70) {
                so_ca_uu_tien++;
                printf("Benh nhan %d | Tuoi: %d | BHYT: %d | Phi: %d VND | Luong: UU TIEN\n", 
                       i + 1, tuoi, bhyt, phi_kham[i]);
            } else {
                printf("Benh nhan %d | Tuoi: %d | BHYT: %d | Phi: %d VND | Luong: THUONG\n", 
                       i + 1, tuoi, bhyt, phi_kham[i]);
            }
        }
    }


    printf("\n=========================================\n");
    printf("           TONG HOP BAO CAO CA TRUC       \n");
    printf("=========================================\n");
    printf("Tong doanh thu phi kham thuc te: %d VND\n", tong_doanh_thu);
    printf("Tong so ca thuoc luong UU TIEN:    %d ca\n", so_ca_uu_tien);
    printf("=========================================\n");

    return 0;
}