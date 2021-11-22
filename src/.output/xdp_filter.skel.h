/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __XDP_FILTER_BPF_SKEL_H__
#define __XDP_FILTER_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct xdp_filter_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *xdp_receive;
	} progs;
	struct {
		struct bpf_link *xdp_receive;
	} links;
	struct xdp_filter_bpf__rodata {
		char xdp_receive_____fmt[15];
		char xdp_receive_____fmt_1[15];
	} *rodata;
};

static void
xdp_filter_bpf__destroy(struct xdp_filter_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
xdp_filter_bpf__create_skeleton(struct xdp_filter_bpf *obj);

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct xdp_filter_bpf *obj;

	obj = (struct xdp_filter_bpf *)calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (xdp_filter_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	xdp_filter_bpf__destroy(obj);
	return NULL;
}

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open(void)
{
	return xdp_filter_bpf__open_opts(NULL);
}

static inline int
xdp_filter_bpf__load(struct xdp_filter_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open_and_load(void)
{
	struct xdp_filter_bpf *obj;

	obj = xdp_filter_bpf__open();
	if (!obj)
		return NULL;
	if (xdp_filter_bpf__load(obj)) {
		xdp_filter_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
xdp_filter_bpf__attach(struct xdp_filter_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
xdp_filter_bpf__detach(struct xdp_filter_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
xdp_filter_bpf__create_skeleton(struct xdp_filter_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "xdp_filter_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "xdp_filt.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "xdp_receive";
	s->progs[0].prog = &obj->progs.xdp_receive;
	s->progs[0].link = &obj->links.xdp_receive;

	s->data_sz = 3568;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb0\x0a\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0d\0\
\x0c\0\xbf\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\x0f\
\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\x02\0\0\0\x61\x61\0\0\0\0\0\0\x61\x62\x04\
\0\0\0\0\0\xbf\x13\0\0\0\0\0\0\x07\x03\0\0\x0e\0\0\0\x2d\x23\x11\0\0\0\0\0\xbf\
\x13\0\0\0\0\0\0\x07\x03\0\0\x22\0\0\0\x2d\x23\x0e\0\0\0\0\0\xbf\x13\0\0\0\0\0\
\0\x07\x03\0\0\x2a\0\0\0\x2d\x23\x0b\0\0\0\0\0\x71\x14\x17\0\0\0\0\0\x55\x04\
\x09\0\x11\0\0\0\x69\x14\x24\0\0\0\0\0\x55\x04\x07\0\x13\x8d\0\0\xbf\x14\0\0\0\
\0\0\0\x07\x04\0\0\x2e\0\0\0\x2d\x24\x04\0\0\0\0\0\x69\x12\x26\0\0\0\0\0\x55\
\x02\x02\0\0\x0c\0\0\x71\x32\0\0\0\0\0\0\x15\x02\x01\0\x74\0\0\0\x95\0\0\0\0\0\
\0\0\x71\x12\x2b\0\0\0\0\0\x15\x02\x01\0\x65\0\0\0\x05\0\xfc\xff\0\0\0\0\x71\
\x12\x2c\0\0\0\0\0\x55\x02\xfa\xff\x73\0\0\0\x71\x11\x2d\0\0\0\0\0\x55\x01\xf8\
\xff\x74\0\0\0\x18\x01\0\0\x0f\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\x0f\0\0\0\x85\
\0\0\0\x06\0\0\0\xb7\0\0\0\x01\0\0\0\x05\0\xf2\xff\0\0\0\0\x44\x75\x61\x6c\x20\
\x42\x53\x44\x2f\x47\x50\x4c\0\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\
\x64\x0a\0\x42\x50\x46\x20\x66\x69\x6e\x69\x73\x68\x65\x64\x0a\x20\0\x9f\xeb\
\x01\0\x18\0\0\0\0\0\0\0\x74\x01\0\0\x74\x01\0\0\xa3\x02\0\0\0\0\0\0\0\0\0\x02\
\x02\0\0\0\x01\0\0\0\x06\0\0\x04\x18\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\x0d\0\0\
\0\x03\0\0\0\x20\0\0\0\x16\0\0\0\x03\0\0\0\x40\0\0\0\x20\0\0\0\x03\0\0\0\x60\0\
\0\0\x30\0\0\0\x03\0\0\0\x80\0\0\0\x3f\0\0\0\x03\0\0\0\xa0\0\0\0\x4e\0\0\0\0\0\
\0\x08\x04\0\0\0\x54\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\x0d\
\x06\0\0\0\x61\0\0\0\x01\0\0\0\x65\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x69\0\
\0\0\x01\0\0\x0c\x05\0\0\0\x48\x02\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\
\0\0\0\x03\0\0\0\0\x08\0\0\0\x0a\0\0\0\x0d\0\0\0\x4d\x02\0\0\0\0\0\x01\x04\0\0\
\0\x20\0\0\0\x61\x02\0\0\0\0\0\x0e\x09\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x0a\x08\0\
\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0c\0\0\0\x0a\0\0\0\x0f\0\0\0\x69\x02\0\0\0\0\0\
\x0e\x0d\0\0\0\0\0\0\0\x7d\x02\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\x93\x02\0\0\x02\
\0\0\x0f\0\0\0\0\x0e\0\0\0\0\0\0\0\x0f\0\0\0\x0f\0\0\0\x0f\0\0\0\x0f\0\0\0\x9b\
\x02\0\0\x01\0\0\x0f\0\0\0\0\x0b\0\0\0\0\0\0\0\x0d\0\0\0\0\x78\x64\x70\x5f\x6d\
\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\x65\x6e\x64\0\x64\x61\x74\x61\x5f\
\x6d\x65\x74\x61\0\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\
\0\x72\x78\x5f\x71\x75\x65\x75\x65\x5f\x69\x6e\x64\x65\x78\0\x65\x67\x72\x65\
\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\
\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x63\x74\x78\0\x69\x6e\x74\0\x78\x64\x70\
\x5f\x72\x65\x63\x65\x69\x76\x65\0\x78\x64\x70\x5f\x70\x72\x6f\x67\0\x2f\x68\
\x6f\x6d\x65\x2f\x6f\x73\x62\x6f\x78\x65\x73\x2f\x54\x46\x47\x2f\x73\x72\x63\
\x2f\x65\x62\x70\x66\x2f\x78\x64\x70\x5f\x66\x69\x6c\x74\x65\x72\x2e\x62\x70\
\x66\x2e\x63\0\x69\x6e\x74\x20\x78\x64\x70\x5f\x72\x65\x63\x65\x69\x76\x65\x28\
\x73\x74\x72\x75\x63\x74\x20\x78\x64\x70\x5f\x6d\x64\x20\x2a\x63\x74\x78\x29\0\
\x20\x20\x20\x20\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\x6b\x28\x22\x42\x50\x46\
\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x5c\x6e\x22\x29\x3b\0\x20\x20\x20\x20\
\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\x61\x20\x3d\x20\x28\x76\x6f\x69\x64\x20\
\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x63\x74\x78\x2d\x3e\x64\x61\x74\x61\x3b\0\x20\
\x20\x20\x20\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\x61\x5f\x65\x6e\x64\x20\x3d\
\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x63\x74\x78\x2d\
\x3e\x64\x61\x74\x61\x5f\x65\x6e\x64\x3b\0\x20\x20\x20\x20\x69\x66\x20\x28\x28\
\x76\x6f\x69\x64\x20\x2a\x29\x65\x74\x68\x20\x2b\x20\x73\x69\x7a\x65\x6f\x66\
\x28\x2a\x65\x74\x68\x29\x20\x3e\x20\x64\x61\x74\x61\x5f\x65\x6e\x64\x29\0\x20\
\x20\x20\x20\x69\x66\x20\x28\x69\x70\x2d\x3e\x70\x72\x6f\x74\x6f\x63\x6f\x6c\
\x20\x21\x3d\x20\x49\x50\x50\x52\x4f\x54\x4f\x5f\x55\x44\x50\x29\0\x20\x20\x20\
\x20\x69\x66\x20\x28\x75\x64\x70\x2d\x3e\x64\x65\x73\x74\x20\x21\x3d\x20\x6e\
\x74\x6f\x68\x73\x28\x35\x30\x30\x35\x29\x29\0\x20\x20\x20\x20\x69\x66\x20\x28\
\x70\x61\x79\x6c\x6f\x61\x64\x5f\x73\x69\x7a\x65\x20\x21\x3d\x20\x73\x69\x7a\
\x65\x6f\x66\x28\x6d\x61\x74\x63\x68\x5f\x70\x61\x74\x74\x65\x72\x6e\x29\x20\
\x2d\x20\x31\x29\x20\0\x20\x20\x20\x20\x20\x20\x20\x20\x69\x66\x20\x28\x70\x61\
\x79\x6c\x6f\x61\x64\x5b\x69\x5d\x20\x21\x3d\x20\x6d\x61\x74\x63\x68\x5f\x70\
\x61\x74\x74\x65\x72\x6e\x5b\x69\x5d\x29\0\x7d\0\x20\x20\x20\x20\x62\x70\x66\
\x5f\x70\x72\x69\x6e\x74\x6b\x28\x22\x42\x50\x46\x20\x66\x69\x6e\x69\x73\x68\
\x65\x64\x5c\x6e\x20\x22\x29\x3b\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\
\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x4c\x49\x43\x45\x4e\x53\
\x45\0\x78\x64\x70\x5f\x72\x65\x63\x65\x69\x76\x65\x2e\x5f\x5f\x5f\x5f\x66\x6d\
\x74\0\x78\x64\x70\x5f\x72\x65\x63\x65\x69\x76\x65\x2e\x5f\x5f\x5f\x5f\x66\x6d\
\x74\x2e\x31\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x9f\
\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x4c\x01\0\0\x60\x01\0\0\0\0\0\
\0\x08\0\0\0\x75\0\0\0\x01\0\0\0\0\0\0\0\x07\0\0\0\x10\0\0\0\x75\0\0\0\x14\0\0\
\0\0\0\0\0\x7e\0\0\0\xaa\0\0\0\0\xc4\0\0\x08\0\0\0\x7e\0\0\0\xce\0\0\0\x05\xcc\
\0\0\x30\0\0\0\x7e\0\0\0\xf1\0\0\0\x25\xd8\0\0\x38\0\0\0\x7e\0\0\0\x1b\x01\0\0\
\x29\xd4\0\0\x40\0\0\0\x7e\0\0\0\x4d\x01\0\0\x15\x14\x01\0\x50\0\0\0\x7e\0\0\0\
\x4d\x01\0\0\x09\x14\x01\0\x80\0\0\0\x7e\0\0\0\x7c\x01\0\0\x09\x30\x01\0\x98\0\
\0\0\x7e\0\0\0\xa1\x01\0\0\x0e\x4c\x01\0\xa0\0\0\0\x7e\0\0\0\xa1\x01\0\0\x09\
\x4c\x01\0\xb8\0\0\0\x7e\0\0\0\xc3\x01\0\0\x09\x64\x01\0\xd0\0\0\0\x7e\0\0\0\
\xf7\x01\0\0\x0d\x90\x01\0\xd8\0\0\0\x7e\0\0\0\xf7\x01\0\0\x0d\x90\x01\0\xe0\0\
\0\0\x7e\0\0\0\x23\x02\0\0\x01\xcc\x01\0\xe8\0\0\0\x7e\0\0\0\xf7\x01\0\0\x0d\
\x90\x01\0\xf0\0\0\0\x7e\0\0\0\xf7\x01\0\0\x0d\x90\x01\0\0\x01\0\0\x7e\0\0\0\
\xf7\x01\0\0\x0d\x90\x01\0\x08\x01\0\0\x7e\0\0\0\xf7\x01\0\0\x0d\x90\x01\0\x10\
\x01\0\0\x7e\0\0\0\xf7\x01\0\0\x0d\x90\x01\0\x18\x01\0\0\x7e\0\0\0\xf7\x01\0\0\
\x0d\x90\x01\0\x20\x01\0\0\x7e\0\0\0\x25\x02\0\0\x05\x9c\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa4\0\0\0\0\0\x02\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x87\0\0\0\0\0\x02\0\xe8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\
\0\0\0\0\0\x02\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x14\0\0\0\x01\0\x04\0\0\0\0\
\0\0\0\0\0\x0f\0\0\0\0\0\0\0\x8e\0\0\0\x01\0\x04\0\x0f\0\0\0\0\0\0\0\x0f\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\0\0\0\x11\0\x03\0\0\0\0\0\0\0\0\0\x0d\0\
\0\0\0\0\0\0\x43\0\0\0\x12\0\x02\0\0\0\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x60\x01\
\0\0\0\0\0\0\x0a\0\0\0\x07\0\0\0\x6c\x01\0\0\0\0\0\0\x0a\0\0\0\x07\0\0\0\x84\
\x01\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\x2c\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x40\0\0\
\0\0\0\0\0\0\0\0\0\x06\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x60\0\0\0\0\0\
\0\0\0\0\0\0\x06\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x80\0\0\0\0\0\0\0\0\
\0\0\0\x06\0\0\0\x90\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\xa0\0\0\0\0\0\0\0\0\0\0\0\
\x06\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\xc0\0\0\0\0\0\0\0\0\0\0\0\x06\0\
\0\0\xd0\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\xe0\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\
\xf0\0\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x10\
\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x20\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x30\
\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x40\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x50\
\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x60\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x70\
\x01\0\0\0\0\0\0\0\0\0\0\x06\0\0\0\x0f\x0e\x05\x06\0\x2e\x74\x65\x78\x74\0\x2e\
\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x78\x64\x70\x5f\x72\x65\x63\x65\
\x69\x76\x65\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x72\x65\x6c\x78\x64\x70\x5f\
\x70\x72\x6f\x67\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\x67\0\x78\
\x64\x70\x5f\x72\x65\x63\x65\x69\x76\x65\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x6f\x64\x61\
\x74\x61\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\x4c\
\x42\x42\x30\x5f\x39\0\x4c\x42\x42\x30\x5f\x37\0\x78\x64\x70\x5f\x72\x65\x63\
\x65\x69\x76\x65\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\x2e\x31\0\x4c\x42\x42\x30\x5f\
\x31\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\
\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2c\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4f\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x90\x01\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x67\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9d\x01\0\
\0\0\0\0\0\x1e\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x73\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbb\x01\0\0\0\0\0\0\x2f\
\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xea\x05\0\0\0\0\0\0\x80\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5f\0\0\0\x02\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x07\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\x0c\0\0\0\
\x08\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x28\0\0\0\x09\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x60\x08\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x07\0\0\0\x02\0\0\0\
\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x6f\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x80\x08\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x07\0\0\0\x05\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x07\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xb0\x08\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x07\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x35\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x0a\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x57\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\x0a\0\0\0\0\0\
\0\xac\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __XDP_FILTER_BPF_SKEL_H__ */
