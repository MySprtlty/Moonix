#ifndef EVENT_H_
#define EVENT_H_

typedef enum event_flag_t
{
    EVENT_FLAG_NULL = 0x00000000,

    EVENT_FLAG_Reserved00 = 0x00000001,
    EVENT_FLAG_Reserved01 = 0x00000002,
    EVENT_FLAG_Reserved02 = 0x00000004,
    EVENT_FLAG_Reserved03 = 0x00000008,
    EVENT_FLAG_Reserved04 = 0x00000010,
    EVENT_FLAG_Reserved05 = 0x00000020,
    EVENT_FLAG_Reserved06 = 0x00000040,
    EVENT_FLAG_Reserved07 = 0x00000080,
    EVENT_FLAG_Reserved08 = 0x00000100,
    EVENT_FLAG_Reserved09 = 0x00000200,
    EVENT_FLAG_Reserved10 = 0x00000400,
    EVENT_FLAG_Reserved11 = 0x00000800,
    EVENT_FLAG_Reserved12 = 0x00001000,
    EVENT_FLAG_Reserved13 = 0x00002000,
    EVENT_FLAG_Reserved14 = 0x00004000,
    EVENT_FLAG_Reserved15 = 0x00008000,
    EVENT_FLAG_Reserved16 = 0x00010000,
    EVENT_FLAG_Reserved17 = 0x00020000,
    EVENT_FLAG_Reserved18 = 0x00040000,
    EVENT_FLAG_Reserved19 = 0x00080000,
    EVENT_FLAG_Reserved20 = 0x00100000,
    EVENT_FLAG_Reserved21 = 0x00200000,
    EVENT_FLAG_Reserved22 = 0x00400000,
    EVENT_FLAG_Reserved23 = 0x00800000,
    EVENT_FLAG_Reserved24 = 0x01000000,
    EVENT_FLAG_Reserved25 = 0x02000000,
    EVENT_FLAG_Reserved26 = 0x04000000,
    EVENT_FLAG_Reserved27 = 0x08000000,
    EVENT_FLAG_Reserved28 = 0x10000000,
    EVENT_FLAG_Reserved29 = 0x20000000,
    EVENT_FLAG_Reserved30 = 0x40000000,
    EVENT_FLAG_Reserved31 = 0x80000000
}event_flag_t;

typedef void (*defEH)(void); /*default event handler*/
void event_flag_init(void);
void event_flag_set(event_flag_t);
void event_flag_clear(event_flag_t);
bool event_flag_check(event_flag_t);
uint32_t event_flag_to_index(event_flag_t);
void register_defEH(event_flag_t, defEH);
void remove_defEH(event_flag_t);

#endif /*EVENT_H_*/