#ifndef RULES_RGS_H_EXT_DET
#define RULES_RGS_H_EXT_DET

#define LOOK_FOR_RULE_CHAIN_EXT() \
if (initial_state2 < initial_state1) {\
	combined_state = (initial_state2 << 16) | initial_state1;\
	swap = true;\
}\
else {\
	combined_state = (initial_state1 << 16) | initial_state2;\
}\
if(new_link) { \
	switch(combined_state) { \
	case 0x0 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x1;\
			final_state2 = 0x2;\
			rule_type = 1; \
			break; \
		}\
	case 0x1020202 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x4;\
			final_state2 = 0x3;\
			rule_type = 1; \
			break; \
		}\
	case 0x1020802 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0xA;\
			final_state2 = 0x9;\
			rule_type = 1; \
			break; \
		}\
	default: \
		rule_type = 0; \
		break; \
	}; \
} \
else { \
	switch(combined_state) { \
	default: \
		rule_type = 0; \
		break; \
	}; \
	if (rule_type == 0) { \
		switch(combined_state) { \
	case 0x2000402 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x8;\
			final_state2 = 0x7;\
			rule_type = 1; \
			break; \
		}\
	case 0x1000302 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x6;\
			final_state2 = 0x5;\
			rule_type = 1; \
			break; \
		}\
	case 0x7000902 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0xC;\
			final_state2 = 0xB;\
			rule_type = 1; \
			break; \
		}\
	case 0x2000A02 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0xE;\
			final_state2 = 0xD;\
			rule_type = 1; \
			break; \
		}\
	case 0x3020600 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x2;\
			final_state2 = 0x1;\
			rule_type = 1; \
			break; \
		}\
	case 0x4020800 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x1;\
			final_state2 = 0x2;\
			rule_type = 1; \
			break; \
		}\
	case 0x5020702 :\
		if (random_number < RAND_MAX/100) {\
			final_state1 = 0x3;\
			final_state2 = 0x4;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm)%4;\
			ln_abs2 = (engaged_epm)%4;\
			break; \
		}\
	case 0x9020B02 :\
		if (random_number < 0) {\
			final_state1 = 0x8;\
			final_state2 = 0x1;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm+2)%4;\
			ln_abs2 = (engaged_epm+2)%4;\
			break; \
		}\
		default: \
			rule_type = 0; \
			break; \
		}; \
	}; \
}; 
#endif