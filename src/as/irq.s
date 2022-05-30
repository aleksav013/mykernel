.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15
.global irq16
.global irq17
.global irq18
.global irq19
.global irq20
.global irq21
.global irq22
.global irq23
.global irq24
.global irq25
.global irq26
.global irq27
.global irq28
.global irq29
.global irq30
.global irq31
.global timer_irq
.global keyboard_irq
.global irq34
.global irq35
.global irq36
.global irq37
.global irq38
.global irq39
.global irq40
.global irq41
.global irq42
.global irq43
.global irq44
.global irq45
.global irq46
.global irq47
.global irq48
.global irq49
.global irq50
.global irq51
.global irq52
.global irq53
.global irq54
.global irq55
.global irq56
.global irq57
.global irq58
.global irq59
.global irq60
.global irq61
.global irq62
.global irq63
.global irq64
.global irq65
.global irq66
.global irq67
.global irq68
.global irq69
.global irq70
.global irq71
.global irq72
.global irq73
.global irq74
.global irq75
.global irq76
.global irq77
.global irq78
.global irq79
.global irq80
.global irq81
.global irq82
.global irq83
.global irq84
.global irq85
.global irq86
.global irq87
.global irq88
.global irq89
.global irq90
.global irq91
.global irq92
.global irq93
.global irq94
.global irq95
.global irq96
.global irq97
.global irq98
.global irq99
.global irq100
.global irq101
.global irq102
.global irq103
.global irq104
.global irq105
.global irq106
.global irq107
.global irq108
.global irq109
.global irq110
.global irq111
.global irq112
.global irq113
.global irq114
.global irq115
.global irq116
.global irq117
.global irq118
.global irq119
.global irq120
.global irq121
.global irq122
.global irq123
.global irq124
.global irq125
.global irq126
.global irq127
.global irq128
.global irq129
.global irq130
.global irq131
.global irq132
.global irq133
.global irq134
.global irq135
.global irq136
.global irq137
.global irq138
.global irq139
.global irq140
.global irq141
.global irq142
.global irq143
.global irq144
.global irq145
.global irq146
.global irq147
.global irq148
.global irq149
.global irq150
.global irq151
.global irq152
.global irq153
.global irq154
.global irq155
.global irq156
.global irq157
.global irq158
.global irq159
.global irq160
.global irq161
.global irq162
.global irq163
.global irq164
.global irq165
.global irq166
.global irq167
.global irq168
.global irq169
.global irq170
.global irq171
.global irq172
.global irq173
.global irq174
.global irq175
.global irq176
.global irq177
.global irq178
.global irq179
.global irq180
.global irq181
.global irq182
.global irq183
.global irq184
.global irq185
.global irq186
.global irq187
.global irq188
.global irq189
.global irq190
.global irq191
.global irq192
.global irq193
.global irq194
.global irq195
.global irq196
.global irq197
.global irq198
.global irq199
.global irq200
.global irq201
.global irq202
.global irq203
.global irq204
.global irq205
.global irq206
.global irq207
.global irq208
.global irq209
.global irq210
.global irq211
.global irq212
.global irq213
.global irq214
.global irq215
.global irq216
.global irq217
.global irq218
.global irq219
.global irq220
.global irq221
.global irq222
.global irq223
.global irq224
.global irq225
.global irq226
.global irq227
.global irq228
.global irq229
.global irq230
.global irq231
.global irq232
.global irq233
.global irq234
.global irq235
.global irq236
.global irq237
.global irq238
.global irq239
.global irq240
.global irq241
.global irq242
.global irq243
.global irq244
.global irq245
.global irq246
.global irq247
.global irq248
.global irq249
.global irq250
.global irq251
.global irq252
.global irq253
.global irq254
.global irq255


irq0:
    pushal
    cld
    call irq0_handler
    popal
    iretl

irq1:
    pushal
    cld
    call irq1_handler
    popal
    iretl

irq2:
    pushal
    cld
    call irq2_handler
    popal
    iretl

irq3:
    pushal
    cld
    call irq3_handler
    popal
    iretl

irq4:
    pushal
    cld
    call irq4_handler
    popal
    iretl

irq5:
    pushal
    cld
    call irq5_handler
    popal
    iretl

irq6:
    pushal
    cld
    call irq6_handler
    popal
    iretl

irq7:
    pushal
    cld
    call irq7_handler
    popal
    iretl

irq8:
    pushal
    cld
    call irq8_handler
    popal
    iretl

irq9:
    pushal
    cld
    call irq9_handler
    popal
    iretl

irq10:
    pushal
    cld
    call irq10_handler
    popal
    iretl

irq11:
    pushal
    cld
    call irq11_handler
    popal
    iretl

irq12:
    pushal
    cld
    call irq12_handler
    popal
    iretl

irq13:
    pushal
    cld
    call irq13_handler
    popal
    iretl

irq14:
    pushal
    cld
    call irq14_handler
    popal
    iretl

irq15:
    pushal
    cld
    call irq15_handler
    popal
    iretl

irq16:
    pushal
    cld
    call irq16_handler
    popal
    iretl

irq17:
    pushal
    cld
    call irq17_handler
    popal
    iretl

irq18:
    pushal
    cld
    call irq18_handler
    popal
    iretl

irq19:
    pushal
    cld
    call irq19_handler
    popal
    iretl

irq20:
    pushal
    cld
    call irq20_handler
    popal
    iretl

irq21:
    pushal
    cld
    call irq21_handler
    popal
    iretl

irq22:
    pushal
    cld
    call irq22_handler
    popal
    iretl

irq23:
    pushal
    cld
    call irq23_handler
    popal
    iretl

irq24:
    pushal
    cld
    call irq24_handler
    popal
    iretl

irq25:
    pushal
    cld
    call irq25_handler
    popal
    iretl

irq26:
    pushal
    cld
    call irq26_handler
    popal
    iretl

irq27:
    pushal
    cld
    call irq27_handler
    popal
    iretl

irq28:
    pushal
    cld
    call irq28_handler
    popal
    iretl

irq29:
    pushal
    cld
    call irq29_handler
    popal
    iretl

irq30:
    pushal
    cld
    call irq30_handler
    popal
    iretl

irq31:
    pushal
    cld
    call irq31_handler
    popal
    iretl

timer_irq:
    pushal
    cld
    call timer_handler
    popal
    iretl

keyboard_irq:
    pushal
    cld
    call keyboard_handler
    popal
    iretl

irq34:
    pushal
    cld
    call irq34_handler
    popal
    iretl

irq35:
    pushal
    cld
    call irq35_handler
    popal
    iretl

irq36:
    pushal
    cld
    call irq36_handler
    popal
    iretl

irq37:
    pushal
    cld
    call irq37_handler
    popal
    iretl

irq38:
    pushal
    cld
    call irq38_handler
    popal
    iretl

irq39:
    pushal
    cld
    call irq39_handler
    popal
    iretl

irq40:
    pushal
    cld
    call irq40_handler
    popal
    iretl

irq41:
    pushal
    cld
    call irq41_handler
    popal
    iretl

irq42:
    pushal
    cld
    call irq42_handler
    popal
    iretl

irq43:
    pushal
    cld
    call irq43_handler
    popal
    iretl

irq44:
    pushal
    cld
    call irq44_handler
    popal
    iretl

irq45:
    pushal
    cld
    call irq45_handler
    popal
    iretl

irq46:
    pushal
    cld
    call irq46_handler
    popal
    iretl

irq47:
    pushal
    cld
    call irq47_handler
    popal
    iretl

irq48:
    pushal
    cld
    call irq48_handler
    popal
    iretl

irq49:
    pushal
    cld
    call irq49_handler
    popal
    iretl

irq50:
    pushal
    cld
    call irq50_handler
    popal
    iretl

irq51:
    pushal
    cld
    call irq51_handler
    popal
    iretl

irq52:
    pushal
    cld
    call irq52_handler
    popal
    iretl

irq53:
    pushal
    cld
    call irq53_handler
    popal
    iretl

irq54:
    pushal
    cld
    call irq54_handler
    popal
    iretl

irq55:
    pushal
    cld
    call irq55_handler
    popal
    iretl

irq56:
    pushal
    cld
    call irq56_handler
    popal
    iretl

irq57:
    pushal
    cld
    call irq57_handler
    popal
    iretl

irq58:
    pushal
    cld
    call irq58_handler
    popal
    iretl

irq59:
    pushal
    cld
    call irq59_handler
    popal
    iretl

irq60:
    pushal
    cld
    call irq60_handler
    popal
    iretl

irq61:
    pushal
    cld
    call irq61_handler
    popal
    iretl

irq62:
    pushal
    cld
    call irq62_handler
    popal
    iretl

irq63:
    pushal
    cld
    call irq63_handler
    popal
    iretl

irq64:
    pushal
    cld
    call irq64_handler
    popal
    iretl

irq65:
    pushal
    cld
    call irq65_handler
    popal
    iretl

irq66:
    pushal
    cld
    call irq66_handler
    popal
    iretl

irq67:
    pushal
    cld
    call irq67_handler
    popal
    iretl

irq68:
    pushal
    cld
    call irq68_handler
    popal
    iretl

irq69:
    pushal
    cld
    call irq69_handler
    popal
    iretl

irq70:
    pushal
    cld
    call irq70_handler
    popal
    iretl

irq71:
    pushal
    cld
    call irq71_handler
    popal
    iretl

irq72:
    pushal
    cld
    call irq72_handler
    popal
    iretl

irq73:
    pushal
    cld
    call irq73_handler
    popal
    iretl

irq74:
    pushal
    cld
    call irq74_handler
    popal
    iretl

irq75:
    pushal
    cld
    call irq75_handler
    popal
    iretl

irq76:
    pushal
    cld
    call irq76_handler
    popal
    iretl

irq77:
    pushal
    cld
    call irq77_handler
    popal
    iretl

irq78:
    pushal
    cld
    call irq78_handler
    popal
    iretl

irq79:
    pushal
    cld
    call irq79_handler
    popal
    iretl

irq80:
    pushal
    cld
    call irq80_handler
    popal
    iretl

irq81:
    pushal
    cld
    call irq81_handler
    popal
    iretl

irq82:
    pushal
    cld
    call irq82_handler
    popal
    iretl

irq83:
    pushal
    cld
    call irq83_handler
    popal
    iretl

irq84:
    pushal
    cld
    call irq84_handler
    popal
    iretl

irq85:
    pushal
    cld
    call irq85_handler
    popal
    iretl

irq86:
    pushal
    cld
    call irq86_handler
    popal
    iretl

irq87:
    pushal
    cld
    call irq87_handler
    popal
    iretl

irq88:
    pushal
    cld
    call irq88_handler
    popal
    iretl

irq89:
    pushal
    cld
    call irq89_handler
    popal
    iretl

irq90:
    pushal
    cld
    call irq90_handler
    popal
    iretl

irq91:
    pushal
    cld
    call irq91_handler
    popal
    iretl

irq92:
    pushal
    cld
    call irq92_handler
    popal
    iretl

irq93:
    pushal
    cld
    call irq93_handler
    popal
    iretl

irq94:
    pushal
    cld
    call irq94_handler
    popal
    iretl

irq95:
    pushal
    cld
    call irq95_handler
    popal
    iretl

irq96:
    pushal
    cld
    call irq96_handler
    popal
    iretl

irq97:
    pushal
    cld
    call irq97_handler
    popal
    iretl

irq98:
    pushal
    cld
    call irq98_handler
    popal
    iretl

irq99:
    pushal
    cld
    call irq99_handler
    popal
    iretl

irq100:
    pushal
    cld
    call irq100_handler
    popal
    iretl

irq101:
    pushal
    cld
    call irq101_handler
    popal
    iretl

irq102:
    pushal
    cld
    call irq102_handler
    popal
    iretl

irq103:
    pushal
    cld
    call irq103_handler
    popal
    iretl

irq104:
    pushal
    cld
    call irq104_handler
    popal
    iretl

irq105:
    pushal
    cld
    call irq105_handler
    popal
    iretl

irq106:
    pushal
    cld
    call irq106_handler
    popal
    iretl

irq107:
    pushal
    cld
    call irq107_handler
    popal
    iretl

irq108:
    pushal
    cld
    call irq108_handler
    popal
    iretl

irq109:
    pushal
    cld
    call irq109_handler
    popal
    iretl

irq110:
    pushal
    cld
    call irq110_handler
    popal
    iretl

irq111:
    pushal
    cld
    call irq111_handler
    popal
    iretl

irq112:
    pushal
    cld
    call irq112_handler
    popal
    iretl

irq113:
    pushal
    cld
    call irq113_handler
    popal
    iretl

irq114:
    pushal
    cld
    call irq114_handler
    popal
    iretl

irq115:
    pushal
    cld
    call irq115_handler
    popal
    iretl

irq116:
    pushal
    cld
    call irq116_handler
    popal
    iretl

irq117:
    pushal
    cld
    call irq117_handler
    popal
    iretl

irq118:
    pushal
    cld
    call irq118_handler
    popal
    iretl

irq119:
    pushal
    cld
    call irq119_handler
    popal
    iretl

irq120:
    pushal
    cld
    call irq120_handler
    popal
    iretl

irq121:
    pushal
    cld
    call irq121_handler
    popal
    iretl

irq122:
    pushal
    cld
    call irq122_handler
    popal
    iretl

irq123:
    pushal
    cld
    call irq123_handler
    popal
    iretl

irq124:
    pushal
    cld
    call irq124_handler
    popal
    iretl

irq125:
    pushal
    cld
    call irq125_handler
    popal
    iretl

irq126:
    pushal
    cld
    call irq126_handler
    popal
    iretl

irq127:
    pushal
    cld
    call irq127_handler
    popal
    iretl

irq128:
    pushal
    cld
    call irq128_handler
    popal
    iretl

irq129:
    pushal
    cld
    call irq129_handler
    popal
    iretl

irq130:
    pushal
    cld
    call irq130_handler
    popal
    iretl

irq131:
    pushal
    cld
    call irq131_handler
    popal
    iretl

irq132:
    pushal
    cld
    call irq132_handler
    popal
    iretl

irq133:
    pushal
    cld
    call irq133_handler
    popal
    iretl

irq134:
    pushal
    cld
    call irq134_handler
    popal
    iretl

irq135:
    pushal
    cld
    call irq135_handler
    popal
    iretl

irq136:
    pushal
    cld
    call irq136_handler
    popal
    iretl

irq137:
    pushal
    cld
    call irq137_handler
    popal
    iretl

irq138:
    pushal
    cld
    call irq138_handler
    popal
    iretl

irq139:
    pushal
    cld
    call irq139_handler
    popal
    iretl

irq140:
    pushal
    cld
    call irq140_handler
    popal
    iretl

irq141:
    pushal
    cld
    call irq141_handler
    popal
    iretl

irq142:
    pushal
    cld
    call irq142_handler
    popal
    iretl

irq143:
    pushal
    cld
    call irq143_handler
    popal
    iretl

irq144:
    pushal
    cld
    call irq144_handler
    popal
    iretl

irq145:
    pushal
    cld
    call irq145_handler
    popal
    iretl

irq146:
    pushal
    cld
    call irq146_handler
    popal
    iretl

irq147:
    pushal
    cld
    call irq147_handler
    popal
    iretl

irq148:
    pushal
    cld
    call irq148_handler
    popal
    iretl

irq149:
    pushal
    cld
    call irq149_handler
    popal
    iretl

irq150:
    pushal
    cld
    call irq150_handler
    popal
    iretl

irq151:
    pushal
    cld
    call irq151_handler
    popal
    iretl

irq152:
    pushal
    cld
    call irq152_handler
    popal
    iretl

irq153:
    pushal
    cld
    call irq153_handler
    popal
    iretl

irq154:
    pushal
    cld
    call irq154_handler
    popal
    iretl

irq155:
    pushal
    cld
    call irq155_handler
    popal
    iretl

irq156:
    pushal
    cld
    call irq156_handler
    popal
    iretl

irq157:
    pushal
    cld
    call irq157_handler
    popal
    iretl

irq158:
    pushal
    cld
    call irq158_handler
    popal
    iretl

irq159:
    pushal
    cld
    call irq159_handler
    popal
    iretl

irq160:
    pushal
    cld
    call irq160_handler
    popal
    iretl

irq161:
    pushal
    cld
    call irq161_handler
    popal
    iretl

irq162:
    pushal
    cld
    call irq162_handler
    popal
    iretl

irq163:
    pushal
    cld
    call irq163_handler
    popal
    iretl

irq164:
    pushal
    cld
    call irq164_handler
    popal
    iretl

irq165:
    pushal
    cld
    call irq165_handler
    popal
    iretl

irq166:
    pushal
    cld
    call irq166_handler
    popal
    iretl

irq167:
    pushal
    cld
    call irq167_handler
    popal
    iretl

irq168:
    pushal
    cld
    call irq168_handler
    popal
    iretl

irq169:
    pushal
    cld
    call irq169_handler
    popal
    iretl

irq170:
    pushal
    cld
    call irq170_handler
    popal
    iretl

irq171:
    pushal
    cld
    call irq171_handler
    popal
    iretl

irq172:
    pushal
    cld
    call irq172_handler
    popal
    iretl

irq173:
    pushal
    cld
    call irq173_handler
    popal
    iretl

irq174:
    pushal
    cld
    call irq174_handler
    popal
    iretl

irq175:
    pushal
    cld
    call irq175_handler
    popal
    iretl

irq176:
    pushal
    cld
    call irq176_handler
    popal
    iretl

irq177:
    pushal
    cld
    call irq177_handler
    popal
    iretl

irq178:
    pushal
    cld
    call irq178_handler
    popal
    iretl

irq179:
    pushal
    cld
    call irq179_handler
    popal
    iretl

irq180:
    pushal
    cld
    call irq180_handler
    popal
    iretl

irq181:
    pushal
    cld
    call irq181_handler
    popal
    iretl

irq182:
    pushal
    cld
    call irq182_handler
    popal
    iretl

irq183:
    pushal
    cld
    call irq183_handler
    popal
    iretl

irq184:
    pushal
    cld
    call irq184_handler
    popal
    iretl

irq185:
    pushal
    cld
    call irq185_handler
    popal
    iretl

irq186:
    pushal
    cld
    call irq186_handler
    popal
    iretl

irq187:
    pushal
    cld
    call irq187_handler
    popal
    iretl

irq188:
    pushal
    cld
    call irq188_handler
    popal
    iretl

irq189:
    pushal
    cld
    call irq189_handler
    popal
    iretl

irq190:
    pushal
    cld
    call irq190_handler
    popal
    iretl

irq191:
    pushal
    cld
    call irq191_handler
    popal
    iretl

irq192:
    pushal
    cld
    call irq192_handler
    popal
    iretl

irq193:
    pushal
    cld
    call irq193_handler
    popal
    iretl

irq194:
    pushal
    cld
    call irq194_handler
    popal
    iretl

irq195:
    pushal
    cld
    call irq195_handler
    popal
    iretl

irq196:
    pushal
    cld
    call irq196_handler
    popal
    iretl

irq197:
    pushal
    cld
    call irq197_handler
    popal
    iretl

irq198:
    pushal
    cld
    call irq198_handler
    popal
    iretl

irq199:
    pushal
    cld
    call irq199_handler
    popal
    iretl

irq200:
    pushal
    cld
    call irq200_handler
    popal
    iretl

irq201:
    pushal
    cld
    call irq201_handler
    popal
    iretl

irq202:
    pushal
    cld
    call irq202_handler
    popal
    iretl

irq203:
    pushal
    cld
    call irq203_handler
    popal
    iretl

irq204:
    pushal
    cld
    call irq204_handler
    popal
    iretl

irq205:
    pushal
    cld
    call irq205_handler
    popal
    iretl

irq206:
    pushal
    cld
    call irq206_handler
    popal
    iretl

irq207:
    pushal
    cld
    call irq207_handler
    popal
    iretl

irq208:
    pushal
    cld
    call irq208_handler
    popal
    iretl

irq209:
    pushal
    cld
    call irq209_handler
    popal
    iretl

irq210:
    pushal
    cld
    call irq210_handler
    popal
    iretl

irq211:
    pushal
    cld
    call irq211_handler
    popal
    iretl

irq212:
    pushal
    cld
    call irq212_handler
    popal
    iretl

irq213:
    pushal
    cld
    call irq213_handler
    popal
    iretl

irq214:
    pushal
    cld
    call irq214_handler
    popal
    iretl

irq215:
    pushal
    cld
    call irq215_handler
    popal
    iretl

irq216:
    pushal
    cld
    call irq216_handler
    popal
    iretl

irq217:
    pushal
    cld
    call irq217_handler
    popal
    iretl

irq218:
    pushal
    cld
    call irq218_handler
    popal
    iretl

irq219:
    pushal
    cld
    call irq219_handler
    popal
    iretl

irq220:
    pushal
    cld
    call irq220_handler
    popal
    iretl

irq221:
    pushal
    cld
    call irq221_handler
    popal
    iretl

irq222:
    pushal
    cld
    call irq222_handler
    popal
    iretl

irq223:
    pushal
    cld
    call irq223_handler
    popal
    iretl

irq224:
    pushal
    cld
    call irq224_handler
    popal
    iretl

irq225:
    pushal
    cld
    call irq225_handler
    popal
    iretl

irq226:
    pushal
    cld
    call irq226_handler
    popal
    iretl

irq227:
    pushal
    cld
    call irq227_handler
    popal
    iretl

irq228:
    pushal
    cld
    call irq228_handler
    popal
    iretl

irq229:
    pushal
    cld
    call irq229_handler
    popal
    iretl

irq230:
    pushal
    cld
    call irq230_handler
    popal
    iretl

irq231:
    pushal
    cld
    call irq231_handler
    popal
    iretl

irq232:
    pushal
    cld
    call irq232_handler
    popal
    iretl

irq233:
    pushal
    cld
    call irq233_handler
    popal
    iretl

irq234:
    pushal
    cld
    call irq234_handler
    popal
    iretl

irq235:
    pushal
    cld
    call irq235_handler
    popal
    iretl

irq236:
    pushal
    cld
    call irq236_handler
    popal
    iretl

irq237:
    pushal
    cld
    call irq237_handler
    popal
    iretl

irq238:
    pushal
    cld
    call irq238_handler
    popal
    iretl

irq239:
    pushal
    cld
    call irq239_handler
    popal
    iretl

irq240:
    pushal
    cld
    call irq240_handler
    popal
    iretl

irq241:
    pushal
    cld
    call irq241_handler
    popal
    iretl

irq242:
    pushal
    cld
    call irq242_handler
    popal
    iretl

irq243:
    pushal
    cld
    call irq243_handler
    popal
    iretl

irq244:
    pushal
    cld
    call irq244_handler
    popal
    iretl

irq245:
    pushal
    cld
    call irq245_handler
    popal
    iretl

irq246:
    pushal
    cld
    call irq246_handler
    popal
    iretl

irq247:
    pushal
    cld
    call irq247_handler
    popal
    iretl

irq248:
    pushal
    cld
    call irq248_handler
    popal
    iretl

irq249:
    pushal
    cld
    call irq249_handler
    popal
    iretl

irq250:
    pushal
    cld
    call irq250_handler
    popal
    iretl

irq251:
    pushal
    cld
    call irq251_handler
    popal
    iretl

irq252:
    pushal
    cld
    call irq252_handler
    popal
    iretl

irq253:
    pushal
    cld
    call irq253_handler
    popal
    iretl

irq254:
    pushal
    cld
    call irq254_handler
    popal
    iretl

irq255:
    pushal
    cld
    call irq255_handler
    popal
    iretl
