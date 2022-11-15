#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE4(twodcopy, int* src, int* dest,int row_num, int col_num){
    
    int elements = row_num*col_num;

    int buffer[elements];

    int size = sizeof(long int)*elements;

    if(__copy_from_user(buffer, src, size))
        return -EFAULT;
    if(__copy_to_user(dest, buffer, sizez))
        return -EFAULT;

    return 0;
}