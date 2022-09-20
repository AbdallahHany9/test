#ifndef Utils_H_
#define Utils_H_
#define  SET_BIT(reg,bit) (reg=reg|(1<<bit))
#define  CLEAR_BIT(reg,bit) (reg=reg&(~(1<<bit)))
#define  READ_BIT(reg,bit) ((reg>>bit)&1)
#define  TOGGLE_BIT(reg,bit) (reg=reg^(1<<bit))
#define  WRITE_BIT(reg,bit,val) (reg=(reg&(~(1<<bit)))|(val<<bit))




#endif /* INCFILE1_H_ */