int max(int a[], int length) {

    int retval;     // analogous to $v0

    int first_element = a[0];
    if (length == 1) goto max__base;
    // find max value in rest of array
    int curr_max = max(&a[1], length - 1);
    if (first_element > curr_max) goto max__first_el_gt_curr;

max__ret_curr_max:    
    retval = curr_max;
    goto max__epilogue;

max__first_el_gt_curr:
    curr_max = first_element;
    goto max__ret_curr_max;

max__base:
    retval = first_element;

max__epilogue:
    return retval;

}

int main(void) {
    int array[] = {1, 2, 4, 2, 3, 1};
    printf("%d\n", max(array, 6));
    return 0;
}
