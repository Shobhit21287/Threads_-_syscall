#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE5(twodcopy, int* src, int* dest, int rows, int columns,int row_num, int col_num){
    int *temp1 = dest;
    int *temp2 = src;
    
    int buffer[col_num];

    for(int i = 0 ; i < row_num ; i++){
        if(__copy_from_user(buffer, temp2, sizeof(int)*col_num))
            return -EFAULT;
        if(__copy_to_user(temp1, buffer, sizeof(int)*col_num))
            return -EFAULT;
        temp1 += sizeof(int)*col_num;
        temp2 += sizeof(int)*col_num;
    }
    
    free(temp1);
    free(temp2);
    return 0;
}