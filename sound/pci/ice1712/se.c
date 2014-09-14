/*
 *   ALSA driver for ICEnsemble VT1724 (Envy24HT)
 *
 *   Lowlevel functions for ONKYO WAVIO SE-90PCI and SE-200PCI
 *
 *	Copyright (c) 2007 Shin-ya Okada  sh_okada(at)d4.dion.ne.jp
 *                                        (at) -> @
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */      

#include <asm/io.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <sound/core.h>
#include <sound/tlv.h>

#include "ice1712.h"
#include "envy24ht.h"
#include "se.h"

struct se_spec {
	struct {
		unsigned char ch1, ch2;
	} vol[8];
};

/*                                                                          */
/*                                                                          */
/*                                                                          */
/*
                                              
                    
                   
                                                    
                                
  
                                              
                           
  
                                            
                                                  
                                         
                      
  
                                            
                                          
                                     
                      
                                     
  
  
                        
  
          
                                  
                                                                         
                                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                                           
  
          
                                
                                                                           
                                    
                                    
                                    
                                    
  
          
                                                  
                                                                            
                                        
                                                                    
                               
                                
  
  
                                     
  
                                                               
  
                                                          
                                                            
                                                            
                                                            
  
 */


/*                                                                          */
/*                                                                          */
/*                                                                          */

static void __devinit se200pci_WM8740_init(struct snd_ice1712 *ice)
{
	/*               */
}


static void se200pci_WM8740_set_pro_rate(struct snd_ice1712 *ice,
						unsigned int rate)
{
	/*               */
}


/*                                                                          */
/*                                                                          */
/*                                                                          */

static void se200pci_WM8766_write(struct snd_ice1712 *ice,
					unsigned int addr, unsigned int data)
{
	unsigned int st;
	unsigned int bits;
	int i;
	const unsigned int DATA  = 0x010000;
	const unsigned int CLOCK = 0x020000;
	const unsigned int LOAD  = 0x040000;
	const unsigned int ALL_MASK = (DATA | CLOCK | LOAD);

	snd_ice1712_save_gpio_status(ice);

	st = ((addr & 0x7f) << 9) | (data & 0x1ff);
	snd_ice1712_gpio_set_dir(ice, ice->gpio.direction | ALL_MASK);
	snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask & ~ALL_MASK);
	bits = snd_ice1712_gpio_read(ice) & ~ALL_MASK;

	snd_ice1712_gpio_write(ice, bits);
	for (i = 0; i < 16; i++) {
		udelay(1);
		bits &= ~CLOCK;
		st = (st << 1);
		if (st & 0x10000)
			bits |= DATA;
		else
			bits &= ~DATA;

		snd_ice1712_gpio_write(ice, bits);

		udelay(1);
		bits |= CLOCK;
		snd_ice1712_gpio_write(ice, bits);
	}

	udelay(1);
	bits |= LOAD;
	snd_ice1712_gpio_write(ice, bits);

	udelay(1);
	bits |= (DATA | CLOCK);
	snd_ice1712_gpio_write(ice, bits);

	snd_ice1712_restore_gpio_status(ice);
}

static void se200pci_WM8766_set_volume(struct snd_ice1712 *ice, int ch,
					unsigned int vol1, unsigned int vol2)
{
	switch (ch) {
	case 0:
		se200pci_WM8766_write(ice, 0x000, vol1);
		se200pci_WM8766_write(ice, 0x001, vol2 | 0x100);
		break;
	case 1:
		se200pci_WM8766_write(ice, 0x004, vol1);
		se200pci_WM8766_write(ice, 0x005, vol2 | 0x100);
		break;
	case 2:
		se200pci_WM8766_write(ice, 0x006, vol1);
		se200pci_WM8766_write(ice, 0x007, vol2 | 0x100);
		break;
	}
}

static void __devinit se200pci_WM8766_init(struct snd_ice1712 *ice)
{
	se200pci_WM8766_write(ice, 0x1f, 0x000); /*           */
	udelay(10);

	se200pci_WM8766_set_volume(ice, 0, 0, 0); /*                */
	se200pci_WM8766_set_volume(ice, 1, 0, 0); /*                */
	se200pci_WM8766_set_volume(ice, 2, 0, 0); /*                */

	se200pci_WM8766_write(ice, 0x03, 0x022); /*                        */
	se200pci_WM8766_write(ice, 0x0a, 0x080); /*            */
	se200pci_WM8766_write(ice, 0x12, 0x000); /*       */
	se200pci_WM8766_write(ice, 0x15, 0x000); /*       */
	se200pci_WM8766_write(ice, 0x09, 0x000); /*                   */

	se200pci_WM8766_write(ice, 0x02, 0x124); /*                         */
	se200pci_WM8766_write(ice, 0x02, 0x120); /*                   */
}

static void se200pci_WM8766_set_pro_rate(struct snd_ice1712 *ice,
					unsigned int rate)
{
	if (rate > 96000)
		se200pci_WM8766_write(ice, 0x0a, 0x000); /*            */
	else
		se200pci_WM8766_write(ice, 0x0a, 0x080); /*            */
}


/*                                                                          */
/*                                                                          */
/*                                                                          */

static void se200pci_WM8776_write(struct snd_ice1712 *ice,
					unsigned int addr, unsigned int data)
{
	unsigned int val;

	val = (addr << 9) | data;
	snd_vt1724_write_i2c(ice, 0x34, val >> 8, val & 0xff);
}


static void se200pci_WM8776_set_output_volume(struct snd_ice1712 *ice,
					unsigned int vol1, unsigned int vol2)
{
	se200pci_WM8776_write(ice, 0x03, vol1);
	se200pci_WM8776_write(ice, 0x04, vol2 | 0x100);
}

static void se200pci_WM8776_set_input_volume(struct snd_ice1712 *ice,
					unsigned int vol1, unsigned int vol2)
{
	se200pci_WM8776_write(ice, 0x0e, vol1);
	se200pci_WM8776_write(ice, 0x0f, vol2 | 0x100);
}

static const char *se200pci_sel[] = {
	"LINE-IN", "CD-IN", "MIC-IN", "ALL-MIX", NULL
};

static void se200pci_WM8776_set_input_selector(struct snd_ice1712 *ice,
					       unsigned int sel)
{
	static unsigned char vals[] = {
		/*                         */
		0x10, 0x04, 0x08, 0x1c, 0x03
	};
	if (sel > 4)
		sel = 4;
	se200pci_WM8776_write(ice, 0x15, vals[sel]);
}

static void se200pci_WM8776_set_afl(struct snd_ice1712 *ice, unsigned int afl)
{
	/*                              */
	if (afl)
		se200pci_WM8776_write(ice, 0x16, 0x005);
	else
		se200pci_WM8776_write(ice, 0x16, 0x001);
}

static const char *se200pci_agc[] = {
	"Off", "LimiterMode", "ALCMode", NULL
};

static void se200pci_WM8776_set_agc(struct snd_ice1712 *ice, unsigned int agc)
{
	/*                                       */
	switch (agc) {
	case 0:
		se200pci_WM8776_write(ice, 0x11, 0x000); /*     */
		break;
	case 1:
		se200pci_WM8776_write(ice, 0x10, 0x07b);
		se200pci_WM8776_write(ice, 0x11, 0x100); /*             */
		break;
	case 2:
		se200pci_WM8776_write(ice, 0x10, 0x1fb);
		se200pci_WM8776_write(ice, 0x11, 0x100); /*         */
		break;
	}
}

static void __devinit se200pci_WM8776_init(struct snd_ice1712 *ice)
{
	int i;
	static unsigned short __devinitdata default_values[] = {
		0x100, 0x100, 0x100,
		0x100, 0x100, 0x100,
		0x000, 0x090, 0x000, 0x000,
		0x022, 0x022, 0x022,
		0x008, 0x0cf, 0x0cf, 0x07b, 0x000,
		0x032, 0x000, 0x0a6, 0x001, 0x001
	};

	se200pci_WM8776_write(ice, 0x17, 0x000); /*           */
	/*                                          */
 	/*                                           */
	udelay(10);
	/*                                                               */
	for (i = 0; i < ARRAY_SIZE(default_values); i++)
		se200pci_WM8776_write(ice, i, default_values[i]);

	se200pci_WM8776_set_input_selector(ice, 0);
	se200pci_WM8776_set_afl(ice, 0);
	se200pci_WM8776_set_agc(ice, 0);
	se200pci_WM8776_set_input_volume(ice, 0, 0);
	se200pci_WM8776_set_output_volume(ice, 0, 0);

	/*                                */
	se200pci_WM8776_write(ice, 0x00, 0);
	se200pci_WM8776_write(ice, 0x01, 0);
	se200pci_WM8776_write(ice, 0x02, 0x100);
	se200pci_WM8776_write(ice, 0x0d, 0x080);
}

static void se200pci_WM8776_set_pro_rate(struct snd_ice1712 *ice,
						unsigned int rate)
{
	/*               */
}


/*                                                                          */
/*                                                                          */
/*                                                                          */

static void se200pci_set_pro_rate(struct snd_ice1712 *ice, unsigned int rate)
{
	se200pci_WM8740_set_pro_rate(ice, rate);
	se200pci_WM8766_set_pro_rate(ice, rate);
	se200pci_WM8776_set_pro_rate(ice, rate);
}

struct se200pci_control {
	char *name;
	enum {
		WM8766,
		WM8776in,
		WM8776out,
		WM8776sel,
		WM8776agc,
		WM8776afl
	} target;
	enum { VOLUME1, VOLUME2, BOOLEAN, ENUM } type;
	int ch;
	const char **member;
	const char *comment;
};

static const struct se200pci_control se200pci_cont[] = {
	{
		.name = "Front Playback Volume",
		.target = WM8776out,
		.type = VOLUME1,
		.comment = "Front(green)"
	},
	{
		.name = "Side Playback Volume",
		.target = WM8766,
		.type = VOLUME1,
		.ch = 1,
		.comment = "Surround(orange)"
	},
	{
		.name = "Surround Playback Volume",
		.target = WM8766,
		.type = VOLUME1,
		.ch = 2,
		.comment = "SurroundBack(white)"
	},
	{
		.name = "CLFE Playback Volume",
		.target = WM8766,
		.type = VOLUME1,
		.ch = 0,
		.comment = "Center(Lch)&SubWoofer(Rch)(black)"
	},
	{
		.name = "Capture Volume",
		.target = WM8776in,
		.type = VOLUME2
	},
	{
		.name = "Capture Select",
		.target = WM8776sel,
		.type = ENUM,
		.member = se200pci_sel
	},
	{
		.name = "AGC Capture Mode",
		.target = WM8776agc,
		.type = ENUM,
		.member = se200pci_agc
	},
	{
		.name = "AFL Bypass Playback Switch",
		.target = WM8776afl,
		.type = BOOLEAN
	}
};

static int se200pci_get_enum_count(int n)
{
	const char **member;
	int c;

	member = se200pci_cont[n].member;
	if (!member)
		return 0;
	for (c = 0; member[c]; c++)
		;
	return c;
}

static int se200pci_cont_volume_info(struct snd_kcontrol *kc,
				     struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0; /*      */
	uinfo->value.integer.max = 0xff; /*     */
	return 0;
}

#define se200pci_cont_boolean_info	snd_ctl_boolean_mono_info

static int se200pci_cont_enum_info(struct snd_kcontrol *kc,
				   struct snd_ctl_elem_info *uinfo)
{
	int n, c;

	n = kc->private_value;
	c = se200pci_get_enum_count(n);
	if (!c)
		return -EINVAL;
	uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
	uinfo->count = 1;
	uinfo->value.enumerated.items = c;
	if (uinfo->value.enumerated.item >= c)
		uinfo->value.enumerated.item = c - 1;
	strcpy(uinfo->value.enumerated.name,
	       se200pci_cont[n].member[uinfo->value.enumerated.item]);
	return 0;
}

static int se200pci_cont_volume_get(struct snd_kcontrol *kc,
				    struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	uc->value.integer.value[0] = spec->vol[n].ch1;
	uc->value.integer.value[1] = spec->vol[n].ch2;
	return 0;
}

static int se200pci_cont_boolean_get(struct snd_kcontrol *kc,
				     struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	uc->value.integer.value[0] = spec->vol[n].ch1;
	return 0;
}

static int se200pci_cont_enum_get(struct snd_kcontrol *kc,
				  struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	uc->value.enumerated.item[0] = spec->vol[n].ch1;
	return 0;
}

static void se200pci_cont_update(struct snd_ice1712 *ice, int n)
{
	struct se_spec *spec = ice->spec;
	switch (se200pci_cont[n].target) {
	case WM8766:
		se200pci_WM8766_set_volume(ice,
					   se200pci_cont[n].ch,
					   spec->vol[n].ch1,
					   spec->vol[n].ch2);
		break;

	case WM8776in:
		se200pci_WM8776_set_input_volume(ice,
						 spec->vol[n].ch1,
						 spec->vol[n].ch2);
		break;

	case WM8776out:
		se200pci_WM8776_set_output_volume(ice,
						  spec->vol[n].ch1,
						  spec->vol[n].ch2);
		break;

	case WM8776sel:
		se200pci_WM8776_set_input_selector(ice,
						   spec->vol[n].ch1);
		break;

	case WM8776agc:
		se200pci_WM8776_set_agc(ice, spec->vol[n].ch1);
		break;

	case WM8776afl:
		se200pci_WM8776_set_afl(ice, spec->vol[n].ch1);
		break;

	default:
		break;
	}
}

static int se200pci_cont_volume_put(struct snd_kcontrol *kc,
				    struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	unsigned int vol1, vol2;
	int changed;

	changed = 0;
	vol1 = uc->value.integer.value[0] & 0xff;
	vol2 = uc->value.integer.value[1] & 0xff;
	if (spec->vol[n].ch1 != vol1) {
		spec->vol[n].ch1 = vol1;
		changed = 1;
	}
	if (spec->vol[n].ch2 != vol2) {
		spec->vol[n].ch2 = vol2;
		changed = 1;
	}
	if (changed)
		se200pci_cont_update(ice, n);

	return changed;
}

static int se200pci_cont_boolean_put(struct snd_kcontrol *kc,
				     struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	unsigned int vol1;

	vol1 = !!uc->value.integer.value[0];
	if (spec->vol[n].ch1 != vol1) {
		spec->vol[n].ch1 = vol1;
		se200pci_cont_update(ice, n);
		return 1;
	}
	return 0;
}

static int se200pci_cont_enum_put(struct snd_kcontrol *kc,
				  struct snd_ctl_elem_value *uc)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
	struct se_spec *spec = ice->spec;
	int n = kc->private_value;
	unsigned int vol1;

	vol1 = uc->value.enumerated.item[0];
	if (vol1 >= se200pci_get_enum_count(n))
		return -EINVAL;
	if (spec->vol[n].ch1 != vol1) {
		spec->vol[n].ch1 = vol1;
		se200pci_cont_update(ice, n);
		return 1;
	}
	return 0;
}

static const DECLARE_TLV_DB_SCALE(db_scale_gain1, -12750, 50, 1);
static const DECLARE_TLV_DB_SCALE(db_scale_gain2, -10350, 50, 1);

static int __devinit se200pci_add_controls(struct snd_ice1712 *ice)
{
	int i;
	struct snd_kcontrol_new cont;
	int err;

	memset(&cont, 0, sizeof(cont));
	cont.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
	for (i = 0; i < ARRAY_SIZE(se200pci_cont); i++) {
		cont.private_value = i;
		cont.name = se200pci_cont[i].name;
		cont.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
		cont.tlv.p = NULL;
		switch (se200pci_cont[i].type) {
		case VOLUME1:
		case VOLUME2:
			cont.info = se200pci_cont_volume_info;
			cont.get = se200pci_cont_volume_get;
			cont.put = se200pci_cont_volume_put;
			cont.access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ;
			if (se200pci_cont[i].type == VOLUME1)
				cont.tlv.p = db_scale_gain1;
			else
				cont.tlv.p = db_scale_gain2;
			break;
		case BOOLEAN:
			cont.info = se200pci_cont_boolean_info;
			cont.get = se200pci_cont_boolean_get;
			cont.put = se200pci_cont_boolean_put;
			break;
		case ENUM:
			cont.info = se200pci_cont_enum_info;
			cont.get = se200pci_cont_enum_get;
			cont.put = se200pci_cont_enum_put;
			break;
		default:
			snd_BUG();
			return -EINVAL;
		}
		err = snd_ctl_add(ice->card, snd_ctl_new1(&cont, ice));
		if (err < 0)
			return err;
	}

	return 0;
}


/*                                                                          */
/*                                                                          */
/*                                                                          */
/*
                                              
                                              
                                            
                                            
  
                        
  
           
                                  
                                                                         
                                
                                
                                
                                                    
                                
                                
  
 */

 /*                              */


/*                                                                          */
/*                                                                          */
/*                                                                          */

static int __devinit se_init(struct snd_ice1712 *ice)
{
	struct se_spec *spec;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return -ENOMEM;
	ice->spec = spec;

	if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE90PCI) {
		ice->num_total_dacs = 2;
		ice->num_total_adcs = 0;
		ice->vt1720 = 1;
		return 0;

	} else if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE200PCI) {
		ice->num_total_dacs = 8;
		ice->num_total_adcs = 2;
		se200pci_WM8740_init(ice);
		se200pci_WM8766_init(ice);
		se200pci_WM8776_init(ice);
		ice->gpio.set_pro_rate = se200pci_set_pro_rate;
		return 0;
	}

	return -ENOENT;
}

static int __devinit se_add_controls(struct snd_ice1712 *ice)
{
	int err;

	err = 0;
	/*                                            */
	if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE200PCI)
		err = se200pci_add_controls(ice);

	return err;
}


/*                                                                          */
/*                                                                          */
/*                                                                          */

static unsigned char se200pci_eeprom[] __devinitdata = {
	[ICE_EEP2_SYSCONF]	= 0x4b,	/*                               */
	[ICE_EEP2_ACLINK]	= 0x80,	/*     */
	[ICE_EEP2_I2S]		= 0x78,	/*                        */
	[ICE_EEP2_SPDIF]	= 0xc3,	/*                           */

	[ICE_EEP2_GPIO_DIR]	= 0x02, /*                           */
	[ICE_EEP2_GPIO_DIR1]	= 0x00, /*          */
	[ICE_EEP2_GPIO_DIR2]	= 0x07, /*                           */

	[ICE_EEP2_GPIO_MASK]	= 0x00, /*            */
	[ICE_EEP2_GPIO_MASK1]	= 0x00, /*            */
	[ICE_EEP2_GPIO_MASK2]	= 0x00, /*            */

	[ICE_EEP2_GPIO_STATE]	= 0x00, /*               */
	[ICE_EEP2_GPIO_STATE1]	= 0x00, /*          */
	[ICE_EEP2_GPIO_STATE2]	= 0x07, /*                 */
};

static unsigned char se90pci_eeprom[] __devinitdata = {
	[ICE_EEP2_SYSCONF]	= 0x4b,	/*                               */
	[ICE_EEP2_ACLINK]	= 0x80,	/*     */
	[ICE_EEP2_I2S]		= 0x78,	/*                        */
	[ICE_EEP2_SPDIF]	= 0xc3,	/*                           */

	/*                                 */
};

struct snd_ice1712_card_info snd_vt1724_se_cards[] __devinitdata = {
	{
		.subvendor = VT1724_SUBDEVICE_SE200PCI,
		.name = "ONKYO SE200PCI",
		.model = "se200pci",
		.chip_init = se_init,
		.build_controls = se_add_controls,
		.eeprom_size = sizeof(se200pci_eeprom),
		.eeprom_data = se200pci_eeprom,
	},
	{
		.subvendor = VT1724_SUBDEVICE_SE90PCI,
		.name = "ONKYO SE90PCI",
		.model = "se90pci",
		.chip_init = se_init,
		.build_controls = se_add_controls,
		.eeprom_size = sizeof(se90pci_eeprom),
		.eeprom_data = se90pci_eeprom,
	},
	{} /*          */
};
