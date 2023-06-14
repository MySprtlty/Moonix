#ifndef INCLUDE_CTRLBIT_H_
#define INCLUDE_CTRLBIT_H_

/*set or clear the bit*/
#define SET_BIT(p,n) ((p) |=  (1 << (n)))
#define CLR_BIT(p,n) ((p) &= ~(1 << (n)))

#endif /* INCLUDE_CTRLBIT_H_ */
