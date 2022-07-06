#ifndef RULES_SINGLETON_H_EXT_DET
#define RULES_SINGLETON_H_EXT_DET

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
		}\
		break; \
	case 0x202 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x4;\
			final_state2 = 0x3;\
			rule_type = 1; \
		}\
		break; \
	case 0x402 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x6;\
			final_state2 = 0x5;\
			rule_type = 1; \
		}\
		break; \
	case 0x602 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0x8;\
			final_state2 = 0x7;\
			rule_type = 1; \
		}\
		break; \
	case 0x802 :\
		if (random_number < RAND_MAX) {\
			final_state1 = 0xA;\
			final_state2 = 0x9;\
			rule_type = 1; \
		}\
		break; \
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
	case 0x1000200 :\
		if (random_number < (int)(RAND_MAX*0.1)) {\
			final_state1 = 0x0;\
			final_state2 = 0x0;\
			rule_type = 2; \
			ln_abs1 = 0xFF;\
			ln_abs2 = 0xFF;\
		}\
		break; \
	case 0x3000400 :\
		if (random_number < (int)(RAND_MAX*0.05)) {\
			final_state1 = 0x2;\
			final_state2 = 0x0;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm+2)%4;\
			ln_abs2 = 0xFF;\
		}\
		break; \
	case 0x5000600 :\
		if (random_number < (int)(RAND_MAX*0.2)) {\
			final_state1 = 0x4;\
			final_state2 = 0x0;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm+2)%4;\
			ln_abs2 = 0xFF;\
		}\
		break; \
	case 0x7000800 :\
		if (random_number < (int)(RAND_MAX*0.01)) {\
			final_state1 = 0x6;\
			final_state2 = 0x0;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm+2)%4;\
			ln_abs2 = 0xFF;\
		}\
		break; \
	case 0x9000A00 :\
		if (random_number < 0) {\
			final_state1 = 0x8;\
			final_state2 = 0x0;\
			rule_type = 2; \
			ln_abs1 = (engaged_epm+2)%4;\
			ln_abs2 = 0xFF;\
		}\
		break; \
		default: \
			rule_type = 0; \
			break; \
		}; \
	}; \
}; 
#endif