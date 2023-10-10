#ifndef LIB_STDLIB_H_
#define LIB_STDLIB_H_

void sleep(uint32_t);
void start_user_timer(void);
uint32_t stop_user_timer(void);
uint32_t rand_int(const uint32_t);
uint32_t rand_range_int(const uint32_t, const uint32_t);
void print_moonix(const uint32_t);

#endif /* LIB_STDLIB_H_ */