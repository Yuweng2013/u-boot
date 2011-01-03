/*
 * Copyright (C) 2010 Dmitry Cherkassov, Sergei Poselenov, Emcraft Systems
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
 *
 */

#ifndef CORE10100_H
#define CORE10100_H

#define MAC_BASE 0x40003000
/* ethernet mac reset flag */
#define MAC_SR (4 << 1)

/* Soft reset controller address */
#define SOFT_RST_CR 0xE0042030

/* Register offsets */
#define CSR0			0x00
#define CSR1			0x08
#define CSR2			0x10
#define CSR3			0x18
#define CSR4			0x20
#define CSR5			0x28
#define CSR6			0x30
#define CSR7			0x38
#define CSR8			0x40
#define CSR9			0x48
#define CSR10			0x50
#define CSR11			0x58

/* Register fields */
#define CSR0_SWR		1
#define CSR0_TAP		(7 << 17)
#define CSR0_DBO		(1 << 20)

#define CSR1_TPD		1


/* CSR5 bits */
#define CSR5_TI				(1<<0)
#define CSR5_TPS			(1<<1)
#define CSR5_TU				(1<<2)

#define CSR5_UNF			(1<<5)
#define CSR5_RI				(1<<6)
#define CSR5_RU				(1<<7)
#define CSR5_RPS			(1<<8)

#define CSR5_ETI			(1<<10)
#define CSR5_GTE			(1<<11)

#define CSR5_ERI			(1<<14)
#define CSR5_AIS			(1<<15)
#define CSR5_NIS			(1<<16)
#define CSR5_RS_SHIFT		17
#define CSR5_RS_MASK		(0x7 << CSR5_RS_SHIFT)
#define CSR5_RS_STOP		0
#define CSR5_TS_SHIFT		20
#define CSR5_TS_MASK		(0x7 << CSR5_TS_SHIFT)
#define CSR5_TS_STOP		0

#if 0
#define CSR5_INT_BITS	(CSR5_NIS_MASK | CSR5_AIS_MASK | CSR5_ERI_MASK | \
	CSR5_GTE_MASK | CSR5_ETI_MASK | CSR5_RPS_MASK | CSR5_RU_MASK | \
	CSR5_RI_MASK | CSR5_UNF_MASK | CSR5_TU_MASK | CSR5_TPS_MASK | CSR5_TI_MASK)
#endif


#define CSR6_SR			(1 << 1)
#define CSR6_PB			(1 << 3)
#define CSR6_PR			(1 << 6)
#define CSR6_PM			(1 << 7)
#define CSR6_FD			(1 << 9)
#define CSR6_ST			(1 << 13)
#define CSR6_SF			(1 << 21)
#define CSR6_TTM		(1 << 22)


 /* Receive all */
#define CSR6_RA_OFFSET   0x30
#define CSR6_RA_MASK     0x40000000UL
#define CSR6_RA_SHIFT    30


/* Interrupt enable register */
#define CSR7_TIE  (1)
#define CSR7_TSE  (1 << 1)
#define CSR7_RIE  (1 << 6)
#define CSR7_RUE  (1 << 7)
#define CSR7_RSE  (1 << 8)
#define CSR7_AIE  (1 << 15)
#define CSR7_NIE  (1 << 16)


#define CSR9_MDC		(1 << 16)
#define CSR9_MDO		(1 << 17)
#define CSR9_MDEN		(1 << 18)
#define CSR9_MDI		(1 << 19)


/* Descriptor flags */
#define DESC_OWN		(1 << 31)
/* Tx descs */
#define DESC_TES		(1 << 15)
#define DESC_TLO		(1 << 11)
#define DESC_TDE		(1 << 0)
#define DESC_TNC		(1 << 10)
#define DESC_TLC		(1 << 9)
#define DESC_TEC		(1 << 8)
#define DESC_TUF		(1 << 1)
#define DESC_TLS		(1 << 30)
#define DESC_TFS		(1 << 29)
#define DESC_SET		(1 << 27)
#define DESC_TCH		(1 << 24)
#define DESC_TIC		(1 << 31)
#define DESC_TAC		(1 << 26)
#define DESC_DPD		(1 << 23)

/* Rx descs */
#define DESC_RES		(1 << 15)
#define DESC_RFS		(1 << 9)
#define DESC_RLS		(1 << 8)
#define DESC_RDE		(1 << 14)
#define DESC_RRF		(1 << 11)
#define DESC_RMF		(1 << 10)
#define DESC_RTL		(1 << 7)
#define DESC_RCS		(1 << 6)
#define DESC_RFT		(1 << 5)
#define DESC_RRE		(1 << 3)
#define DESC_RDB		(1 << 2)
#define DESC_RCE		(1 << 1)
#define DESC_RFF		(1 << 30)
#define DESC_RZERO		(1 << 0)

#define DESC_RCH		(1 << 24)

/* Link status */
#define LINK_UP			0x01
#define LINK_FD			0x02
#define LINK_100		0x04
#define TX_RX_ENABLED		0x10

/* Timeouts */

#define TIMEOUT_UDELAY		500
#define TIMEOUT_LOOPS		10000

/*Register access functions*/

#define read_reg(reg) (readl(bp->base + reg))
#define write_reg(reg, val) (writel(val, bp->base + reg))

#define RX_RING_SIZE 4
#define TX_RING_SIZE 4

/*MORE REGS*/

/*------------------------------------------------------------------------------
 * CSR0_DSL:
 *   DSL field of register CSR0.
 *------------------------------------------------------------------------------
 * Descriptor skip length
 */
#define CSR0_DSL_MASK     (0x1f << CSR0_DSL_SHIFT)
#define CSR0_DSL_SHIFT    2

/*------------------------------------------------------------------------------
 * CSR0_TAP:
 *   TAP field of register CSR0.
 *------------------------------------------------------------------------------
 * Transmit automatic polling
 */
#define CSR0_TAP_MASK     (0x7 << CSR0_TAP_SHIFT)
#define CSR0_TAP_SHIFT    17


/*--------------------------------------------------------------*/
/*
 * Allowed values for CSR0_TAP:
 *------------------------------------------------------------------------------
 * TAP_DISABLED:   TAP disabled
 * TAP_819US:      TAP 819/81.9us
 * TAP_2450US:     TAP 2450/245us
 * TAP_5730US:     TAP 5730/573us
 * TAP_51_2US:     TAP 51.2/5.12us
 * TAP_102_4US:    TAP 102.4/10.24us
 * TAP_153_6US:    TAP 156.6/15.26us
 * TAP_358_4US:    TAP 358.4/35.84us
 */
#define TAP_DISABLED    0x0
#define TAP_819US       0x1
#define TAP_2450US      0x2
#define TAP_5730US      0x3
#define TAP_51_2US      0x4
#define TAP_102_4US     0x5
#define TAP_153_6US     0x6
#define TAP_358_4US     0x7
/*------------------------------------------------------------------------------*/


/**
 * Size of the max packet that can be received/transmited.
 */
#define MSS_MAX_PACKET_SIZE  1514uL

/**
 * Size of a receive/transmit buffer.
 * Buffer size must be enough big to hold a full frame and must be multiple of
 * four. For rx buffer +4 bytes allocated for crc values. These bytes doesn't
 * copied to the user buffer.
 */
#define MSS_TX_BUFF_SIZE  ((MSS_MAX_PACKET_SIZE + 3u) & (~(uint32_t)3))
#define MSS_RX_BUFF_SIZE  ((MSS_MAX_PACKET_SIZE + 7u) & (~(uint32_t)3))

/***************************************************************************//**
 * Buffer 2 size.
 * Indicates the size, in bytes, of memory space used by the second data buffer. This number must be a
 * multiple of four. If it is 0, Core10/100 ignores the second data buffer and fetches the next data descriptor.
 * This number is valid only when RDES1.24 (second address chained) is cleared.
 */
#define RDES1_RBS2_MASK		0x7FF
#define RDES1_RBS2_OFFSET	11

/***************************************************************************//**
 * Buffer 1 size
 * Indicates the size, in bytes, of memory space used by the first data buffer. This number must be a multiple of
 * four. If it is 0, Core10/100 ignores the first data buffer and uses the second data buffer.
 */
#define RDES1_RBS1_MASK		0x7FF
#define RDES1_RBS1_OFFSET	0

/***************************************************************************//**
 * Receive end of ring.
 * When set, indicates that this is the last descriptor in the receive descriptor ring. Core10/100 returns to the
 * first descriptor in the ring, as specified by CSR3 (start of receive list address).
 */
#define RDES1_RER   0x02000000UL

/***************************************************************************//**
 * Transmit end of ring.
 * When set, indicates the last descriptor in the descriptor ring.
 */
#define TDES1_TER     ((uint32_t)1 << 25)

#define CORE10100_MAX_DATA_SIZE_ALIGNED ((1600+3) &(-4))
/* Receive/transmit descriptor */
struct rxtx_desc {
	unsigned int own_stat;
	unsigned int cntl_size;
	volatile void *buf1;
	volatile void *buf2;
};

struct core10100_dev {
	void *base;
	struct eth_device netdev;
	u32	flags;

	/* RX/TX descriptors */
	volatile struct rxtx_desc *rx_descs __attribute__((aligned(4)));
	volatile struct rxtx_desc *tx_descs __attribute__((aligned(4)));
	volatile struct rxtx_desc *tx_mac __attribute__((aligned(4)));

	/* Current Tx descriptor to be sent by host */
	int tx_cur;
	/* Current Rx descriptor */
	int rx_cur;
	/* mac filter buffer */
	volatile char *mac_filter;

	volatile char *tx_buffs[TX_RING_SIZE] __attribute__((aligned(4)));
	volatile char *rx_buffs[RX_RING_SIZE] __attribute__((aligned(4)));

	u32 phy_id;	/* ID of the PHY */
	u32 phy_addr;
};


#define to_core(_nd) container_of(_nd, struct core10100_dev, netdev)

#endif /* CORE10100_H */

