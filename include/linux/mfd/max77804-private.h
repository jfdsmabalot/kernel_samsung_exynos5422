/*
 * max77804-private.h - Voltage regulator driver for the Maxim 77804
 *
 *  Copyright (C) 2011 Samsung Electrnoics
 *  SangYoung Son <hello.son@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_MAX77804_PRIV_H
#define __LINUX_MFD_MAX77804_PRIV_H

#include <linux/i2c.h>

#define MAX77804_I2C_ADDR		(0x4A >> 1)
#define MAX77804_REG_INVALID		(0xff)

#define MAX77804_IRQSRC_CHG             (1 << 0)
#define MAX77804_IRQSRC_TOP             (1 << 1)
#define MAX77804_IRQSRC_FLASH           (1 << 2)
#define MAX77804_IRQSRC_MUIC            (1 << 3)

enum MAX77804_rev {
	MAX77804_REV_PASS1	= 0x00,
	MAX77804_REV_PASS2	= 0x01,
	MAX77804_REV_PASS3	= 0x02,
};

/* Slave addr = 0xCC: Charger, Flash LED, Haptic */
enum max77804_reg {
	MAX77804_LED_REG_IFLASH				= 0x00,
	MAX77804_LED_REG_RESERVED_01			= 0x01,
	MAX77804_LED_REG_ITORCH				= 0x02,
	MAX77804_LED_REG_ITORCHTORCHTIMER		= 0x03,
	MAX77804_LED_REG_FLASH_TIMER			= 0x04,
	MAX77804_LED_REG_FLASH_EN			= 0x05,
	MAX77804_LED_REG_MAX_FLASH1			= 0x06,
	MAX77804_LED_REG_MAX_FLASH2			= 0x07,
	MAX77804_LED_REG_MAX_FLASH3			= 0x08,
	MAX77804_LED_REG_MAX_FLASH4			= 0x09,
	MAX77804_LED_REG_VOUT_CNTL			= 0x0A,
	MAX77804_LED_REG_VOUT_FLASH			= 0x0B,
	MAX77804_LED_REG_RESERVED_0C			= 0x0C,
	MAX77804_LED_REG_RESERVED_0D			= 0x0D,
	MAX77804_LED_REG_FLASH_INT			= 0x0E,
	MAX77804_LED_REG_FLASH_INT_MASK			= 0x0F,
	MAX77804_LED_REG_FLASH_INT_STATUS		= 0x10,
	MAX77804_LED_REG_RESERVED_11			= 0x11,

	MAX77804_PMIC_REG_PMIC_ID1			= 0x20,
	MAX77804_PMIC_REG_PMIC_ID2			= 0x21,
	MAX77804_PMIC_REG_INTSRC			= 0x22,
	MAX77804_PMIC_REG_INTSRC_MASK			= 0x23,
	MAX77804_PMIC_REG_TOPSYS_INT			= 0x24,
	MAX77804_PMIC_REG_RESERVED_25			= 0x25,
	MAX77804_PMIC_REG_TOPSYS_INT_MASK		= 0x26,
	MAX77804_PMIC_REG_RESERVED_27			= 0x27,
	MAX77804_PMIC_REG_TOPSYS_STAT			= 0x28,
	MAX77804_PMIC_REG_RESERVED_29			= 0x29,
	MAX77804_PMIC_REG_MAINCTRL1			= 0x2A,
	MAX77804_PMIC_REG_LSCNFG			= 0x2B,
	MAX77804_PMIC_REG_RESERVED_2C			= 0x2C,
	MAX77804_PMIC_REG_RESERVED_2D			= 0x2D,

	MAX77804_CHG_REG_CHG_INT			= 0xB0,
	MAX77804_CHG_REG_CHG_INT_MASK			= 0xB1,
	MAX77804_CHG_REG_CHG_INT_OK			= 0xB2,
	MAX77804_CHG_REG_CHG_DTLS_00			= 0xB3,
	MAX77804_CHG_REG_CHG_DTLS_01			= 0xB4,
	MAX77804_CHG_REG_CHG_DTLS_02			= 0xB5,
	MAX77804_CHG_REG_CHG_DTLS_03			= 0xB6,
	MAX77804_CHG_REG_CHG_CNFG_00			= 0xB7,
	MAX77804_CHG_REG_CHG_CNFG_01			= 0xB8,
	MAX77804_CHG_REG_CHG_CNFG_02			= 0xB9,
	MAX77804_CHG_REG_CHG_CNFG_03			= 0xBA,
	MAX77804_CHG_REG_CHG_CNFG_04			= 0xBB,
	MAX77804_CHG_REG_CHG_CNFG_05			= 0xBC,
	MAX77804_CHG_REG_CHG_CNFG_06			= 0xBD,
	MAX77804_CHG_REG_CHG_CNFG_07			= 0xBE,
	MAX77804_CHG_REG_CHG_CNFG_08			= 0xBF,
	MAX77804_CHG_REG_CHG_CNFG_09			= 0xC0,
	MAX77804_CHG_REG_CHG_CNFG_10			= 0xC1,
	MAX77804_CHG_REG_CHG_CNFG_11			= 0xC2,
	MAX77804_CHG_REG_CHG_CNFG_12			= 0xC3,
	MAX77804_CHG_REG_CHG_CNFG_13			= 0xC4,
	MAX77804_CHG_REG_CHG_CNFG_14			= 0xC5,
	MAX77804_CHG_REG_SAFEOUT_CTRL			= 0xC6,

	MAX77804_PMIC_REG_END,
};

/* Slave addr = 0x4A: MUIC */
enum max77804_muic_reg {
	MAX77804_MUIC_REG_ID		= 0x00,
	MAX77804_MUIC_REG_INT1		= 0x01,
	MAX77804_MUIC_REG_INT2		= 0x02,
	MAX77804_MUIC_REG_INT3		= 0x03,
	MAX77804_MUIC_REG_STATUS1	= 0x04,
	MAX77804_MUIC_REG_STATUS2	= 0x05,
#if defined(CONFIG_MUIC_MAX77804)
	MAX77804_MUIC_REG_STATUS3	= 0x06,
#endif /* CONFIG_MUIC_MAX77804 */
	MAX77804_MUIC_REG_INTMASK1	= 0x07,
	MAX77804_MUIC_REG_INTMASK2	= 0x08,
#if defined(CONFIG_MUIC_MAX77804)
	MAX77804_MUIC_REG_INTMASK3	= 0x09,
#endif /* CONFIG_MUIC_MAX77804 */
	MAX77804_MUIC_REG_CDETCTRL1	= 0x0A,
	MAX77804_MUIC_REG_CDETCTRL2	= 0x0B,
	MAX77804_MUIC_REG_CTRL1		= 0x0C,
	MAX77804_MUIC_REG_CTRL2		= 0x0D,
	MAX77804_MUIC_REG_CTRL3		= 0x0E,
#if defined(CONFIG_MUIC_MAX77804K)
	MAX77804_MUIC_REG_CTRL4		= 0x16,
#endif /* CONFIG_MUIC_MAX77804K */

	MAX77804_MUIC_REG_END,
};

/* Slave addr = 0x4A: Charger */
enum max77804_charger_reg {
	MAX77804_CHG_REG_STATUS3	= 0x06,
	MAX77804_CHG_REG_CHG_CTRL1	= 0x0F,
	MAX77804_CHG_REG_CHG_CTRL2	= 0x10,
	MAX77804_CHG_REG_CHG_CTRL3	= 0x11,
	MAX77804_CHG_REG_CHG_CTRL4	= 0x12,
	MAX77804_CHG_REG_CHG_CTRL5	= 0x13,
	MAX77804_CHG_REG_CHG_CTRL6	= 0x14,
	MAX77804_CHG_REG_CHG_CTRL7	= 0x15,

	MAX77804_CHG_REG_END,
};

/* Slave addr = 0x90: Haptic */
enum max77804_haptic_reg {
	MAX77804_HAPTIC_REG_STATUS		= 0x00,
	MAX77804_HAPTIC_REG_CONFIG1		= 0x01,
	MAX77804_HAPTIC_REG_CONFIG2		= 0x02,
	MAX77804_HAPTIC_REG_CONFIG_CHNL		= 0x03,
	MAX77804_HAPTIC_REG_CONFG_CYC1		= 0x04,
	MAX77804_HAPTIC_REG_CONFG_CYC2		= 0x05,
	MAX77804_HAPTIC_REG_CONFIG_PER1		= 0x06,
	MAX77804_HAPTIC_REG_CONFIG_PER2		= 0x07,
	MAX77804_HAPTIC_REG_CONFIG_PER3		= 0x08,
	MAX77804_HAPTIC_REG_CONFIG_PER4		= 0x09,
	MAX77804_HAPTIC_REG_CONFIG_DUTY1	= 0x0A,
	MAX77804_HAPTIC_REG_CONFIG_DUTY2	= 0x0B,
	MAX77804_HAPTIC_REG_CONFIG_PWM1		= 0x0C,
	MAX77804_HAPTIC_REG_CONFIG_PWM2		= 0x0D,
	MAX77804_HAPTIC_REG_CONFIG_PWM3		= 0x0E,
	MAX77804_HAPTIC_REG_CONFIG_PWM4		= 0x0F,
	MAX77804_HAPTIC_REG_REV			= 0x10,

	MAX77804_HAPTIC_REG_END,
};

/* MAX77804 CHG_CNFG_00 register */
#define CHG_CNFG_00_MODE_SHIFT		0
#define CHG_CNFG_00_CHG_SHIFT		0
#define CHG_CNFG_00_OTG_SHIFT		1
#define CHG_CNFG_00_BUCK_SHIFT		2
#define CHG_CNFG_00_BOOST_SHIFT		3
#define CHG_CNFG_00_DIS_MUIC_CTRL_SHIFT	5
#define CHG_CNFG_00_MODE_MASK		(0xf << CHG_CNFG_00_MODE_SHIFT)
#define CHG_CNFG_00_CHG_MASK		(1 << CHG_CNFG_00_CHG_SHIFT)
#define CHG_CNFG_00_OTG_MASK		(1 << CHG_CNFG_00_OTG_SHIFT)
#define CHG_CNFG_00_BUCK_MASK		(1 << CHG_CNFG_00_BUCK_SHIFT)
#define CHG_CNFG_00_BOOST_MASK		(1 << CHG_CNFG_00_BOOST_SHIFT)
#define CHG_CNFG_00_DIS_MUIC_CTRL_MASK	(1 << CHG_CNFG_00_DIS_MUIC_CTRL_SHIFT)

enum max77804_irq_source {
	LED_INT = 0,
	TOPSYS_INT,
	CHG_INT,
	MUIC_INT1,
	MUIC_INT2,
#if defined(CONFIG_MUIC_MAX77804)
	MUIC_INT3,
#endif

	MAX77804_IRQ_GROUP_NR,
};

#if defined(CONFIG_MUIC_MAX77804)
#define MUIC_MAX_INT			MUIC_INT3
#else
#define MUIC_MAX_INT			MUIC_INT2
#endif
#define MAX77804_NUM_IRQ_MUIC_REGS	(MUIC_MAX_INT - MUIC_INT1 + 1)

enum max77804_irq {
	/* PMIC; FLASH */
	MAX77804_LED_IRQ_FLED2_OPEN,
	MAX77804_LED_IRQ_FLED2_SHORT,
	MAX77804_LED_IRQ_FLED1_OPEN,
	MAX77804_LED_IRQ_FLED1_SHORT,
	MAX77804_LED_IRQ_MAX_FLASH,

	/* PMIC; TOPSYS */
	MAX77804_TOPSYS_IRQ_T120C_INT,
	MAX77804_TOPSYS_IRQ_T140C_INT,
	MAX77804_TOPSYS_IRQLOWSYS_INT,

	/* PMIC; Charger */
	MAX77804_CHG_IRQ_BYP_I,
	MAX77804_CHG_IRQ_BATP_I,
	MAX77804_CHG_IRQ_BAT_I,
	MAX77804_CHG_IRQ_CHG_I,
	MAX77804_CHG_IRQ_WCIN_I,
	MAX77804_CHG_IRQ_CHGIN_I,

	/* MUIC INT1 */
	MAX77804_MUIC_IRQ_INT1_ADC,
#if defined(CONFIG_MUIC_MAX77804)
	MAX77804_MUIC_IRQ_INT1_ADCLOW,
#endif /* CONFIG_MUIC_MAX77804 */
	MAX77804_MUIC_IRQ_INT1_ADCERR,
	MAX77804_MUIC_IRQ_INT1_ADC1K,

	/* MUIC INT2 */
	MAX77804_MUIC_IRQ_INT2_CHGTYP,
	MAX77804_MUIC_IRQ_INT2_CHGDETREUN,
	MAX77804_MUIC_IRQ_INT2_DCDTMR,
	MAX77804_MUIC_IRQ_INT2_DXOVP,
	MAX77804_MUIC_IRQ_INT2_VBVOLT,
#if defined(CONFIG_MUIC_MAX77804)
	MAX77804_MUIC_IRQ_INT2_VIDRM,

	/* MUIC INT3 */
	MAX77804_MUIC_IRQ_INT3_EOC,
	MAX77804_MUIC_IRQ_INT3_CGMBC,
	MAX77804_MUIC_IRQ_INT3_OVP,
	MAX77804_MUIC_IRQ_INT3_MBCCHGERR,
	MAX77804_MUIC_IRQ_INT3_CHGENABLED,
	MAX77804_MUIC_IRQ_INT3_BATDET,
#endif /* CONFIG_MUIC_MAS77804 */

	MAX77804_IRQ_NR,
};

struct max77804_dev {
	struct device *dev;
	struct i2c_client *i2c; /* 0xCC; Charger, Flash LED */
	struct i2c_client *muic; /* 0x4A; MUIC */
	struct i2c_client *haptic; /* 0x90; Haptic */
	struct mutex i2c_lock;

	int type;

	int irq;
	int irq_base;
	int irq_gpio;
	bool wakeup;
	struct mutex irqlock;
	int irq_masks_cur[MAX77804_IRQ_GROUP_NR];
	int irq_masks_cache[MAX77804_IRQ_GROUP_NR];

#ifdef CONFIG_HIBERNATION
	/* For hibernation */
	u8 reg_pmic_dump[MAX77804_PMIC_REG_END];
	u8 reg_muic_dump[MAX77804_MUIC_REG_END];
	u8 reg_haptic_dump[MAX77804_HAPTIC_REG_END];
#endif

	/* pmic VER/REV register */
	u8 pmic_rev;	/* pmic Rev */
	u8 pmic_ver;	/* pmic version */

	struct max77804_platform_data *pdata;
};

enum max77804_types {
	TYPE_MAX77804,
};

#if defined(CONFIG_MUIC_MAX77804)
extern int max77804_irq_init(struct max77804_dev *max77804);
extern void max77804_irq_exit(struct max77804_dev *max77804);
extern int max77804_irq_resume(struct max77804_dev *max77804);
#elif defined(CONFIG_MUIC_MAX77804K)
extern int max77804k_irq_init(struct max77804_dev *max77804);
extern void max77804k_irq_exit(struct max77804_dev *max77804);
extern int max77804k_irq_resume(struct max77804_dev *max77804);
#endif

/* MAX77804 shared i2c API function */
extern int max77804_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest);
extern int max77804_bulk_read(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max77804_write_reg(struct i2c_client *i2c, u8 reg, u8 value);
extern int max77804_bulk_write(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max77804_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask);

/* MAX77804 check muic path fucntion */
extern bool is_muic_usb_path_ap_usb(void);
extern bool is_muic_usb_path_cp_usb(void);

#endif /* __LINUX_MFD_MAX77804_PRIV_H */
