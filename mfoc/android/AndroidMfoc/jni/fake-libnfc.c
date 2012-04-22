/** Fake libnfc implementation
 *
 * See http://code.google.com/p/libnfc/ for libnfc source and docs.
 */

#include <nfc/nfc.h>

#include <stdlib.h>
#include <stdio.h>

#define IMPLEMENT_ME ((void)0)

void nfc_perror (const nfc_device *pnd, const char *s)
{
	fprintf(stderr, "nfc_perror called for device %p: %s\n", pnd, s?s:"(null)");;
}

struct nfc_device
{
	char *connstring;
};

nfc_device *nfc_open (nfc_context *context, const nfc_connstring connstring)
{
	fprintf(stderr, "nfc_open: connstring: %s\n", connstring?connstring:"(null)");
	nfc_device *newdev = malloc(sizeof(nfc_device));
	if (connstring)
		newdev->connstring = strdup(connstring);
	return newdev;
}

void nfc_close (nfc_device *pnd)
{
	if (pnd->connstring)
		free(pnd->connstring);
	free(pnd);
}

int nfc_initiator_init (nfc_device *pnd)
{
	fprintf(stderr, "nfc_initiator init called on dev %p\n", pnd);
	return 0;
}

int nfc_initiator_select_passive_target (nfc_device *pnd, const nfc_modulation nm, const uint8_t *pbtInitData, const size_t szInitData, nfc_target *pnt)
{
	fprintf(stderr, "nfc_initiator_select_passive_target called: %p, nm: %d/%d, initdata: %p, szInitData: %ld, target: %p\n", pnd, (int)nm.nmt, (int)nm.nbr, pbtInitData, (long)szInitData, pnt);

	/*TODO: fill data from the card on *pnt, here */
	IMPLEMENT_ME;
	memset(pnt, 0, sizeof(*pnt));
	return 0;
}


/* NOTE: we will probably need some tricks to be able to send raw commands
 * without CRC using the Android API. I hope the system allow us to do
 * that.  :(
 */


int nfc_initiator_transceive_bytes (nfc_device *pnd, const uint8_t *pbtTx, const size_t szTx, uint8_t *pbtRx, size_t *pszRx, int timeout)
{
	IMPLEMENT_ME;
}

int nfc_initiator_transceive_bits (nfc_device *pnd, const uint8_t *pbtTx, const size_t szTxBits, const uint8_t *pbtTxPar, uint8_t *pbtRx, uint8_t *pbtRxPar)
{
	IMPLEMENT_ME;
}

void nfc_init(nfc_context *context)
{
	fprintf(stderr, "nfc_init called\n");
}

void nfc_exit(nfc_context *context)
{
	fprintf(stderr, "nfc_exit called\n");
}


int nfc_device_set_property_bool (nfc_device *pnd, const nfc_property property, const bool bEnable)
{
	IMPLEMENT_ME;
}

void iso14443a_crc_append (uint8_t *pbtData, size_t szLen)
{
	IMPLEMENT_ME;
}