#ifndef WORLD_H_
#define WORLD_H_

enum OBJECT_TYPE
{
    BLANK,
    BOX,
    DISK
};

#define START_UNIT 0        //ΕΜvf

#define BUFFER_WIDTH 19       //BufferΜ‘
#define BUFFER_HEIGHT 6       //BufferΜc

#define BOX_NUM 3            // Μ
#define BOX_WIDTH 5          // Μ‘
#define BOX_HEIGHT 3         // Μc

#define BUFFER_BOX_POS_Y 2         // Μc
	 
#define DISK_NUM 3           //~ΥΜ
#define SMALL_DISK_WIDTH 1   //¬~ΥΜ‘
#define NOMAL_DISK_WIDTH 3   //ΥΜ‘
#define BIG_DISK_WIDTH 5     //εΥΜ‘
#define DISK_HEIGHT 1        //~ΥΜc

#define DISK_MAX_WIDTH 6        //~ΥΜc


#endif 