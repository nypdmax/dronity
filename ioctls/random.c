#include <linux/types.h>
#include <linux/random.h>

#include "utils.h"
#include "ioctls.h"

static const struct ioctl random_ioctls[] = {
	IOCTL(RNDGETENTCNT),
	IOCTL(RNDADDTOENTCNT),
	/* IOCTL(RNDGETPOOL), not supported on android */
	IOCTL(RNDADDENTROPY),
	IOCTL(RNDZAPENTCNT),
	IOCTL(RNDCLEARPOOL),
};

static const char *const random_devs[] = {
	"mem",
};

static const struct ioctl_group random_grp = {
	.name = "random",
	.devtype = DEV_CHAR,
	.devs = random_devs,
	.devs_cnt = ARRAY_SIZE(random_devs),
	.sanitise = pick_random_ioctl,
	.ioctls = random_ioctls,
	.ioctls_cnt = ARRAY_SIZE(random_ioctls),
};

REG_IOCTL_GROUP(random_grp)
