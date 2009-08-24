#import "CSFilterHandle.h"

extern NSString *LZWInvalidCodeException;

typedef struct LZWTreeNode
{
	uint16_t chr;
	int16_t parent;
} LZWTreeNode;

@interface LZWHandle:CSFilterHandle
{
	BOOL early;

	int numsymbols,symbolsize;
	LZWTreeNode *nodes;

	int prevsymbol;

	int currbyte,numbytes;
	uint8_t buffer[4096];
}

-(id)initWithHandle:(CSHandle *)handle earlyChange:(BOOL)earlychange;

-(void)clearTable;

-(void)resetFilter;
-(uint8_t)produceByteAtOffset:(off_t)pos;

@end