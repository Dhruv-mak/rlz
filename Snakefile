import os
# WORKDIR = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
WORKDIR = "/home/dmakwana/boucher/dmakwana/rlzs"

rule compress_sku:
    input:
        WORKDIR + "/data/{reference}.fa",
        WORKDIR + "/data/{sequence}.fa"
    output:
        WORKDIR + "/data/{reference}.fa.sa",
        WORKDIR + "/data/{sequence}.fa.fac"
    benchmark:
        WORKDIR + "/data/skuruppu/{reference}_{sequence}_compress.tsv"
    shell:
        # """
        # {WORKDIR}/RLZ/rlz -e t {WORKDIR}/data/{reference}.fa {WORKDIR}/data/{sequence}.fa
        # """
        " /home/dmakwana/boucher/dmakwana/rlzs/RLZ/rlz -e t /home/dmakwana/boucher/dmakwana/rlzs/data/{reference}.fa /home/dmakwana/boucher/dmakwana/rlzs/data/{sequence}.fa "

rule decompress_sku:
    input:
        WORKDIR + "/data/{reference}.fa.sa",
        WORKDIR + "/data/{sequence}.fa.fac"
    output:
        WORKDIR + "/data/{sequence}.fa.dec"
    benchmark:
        WORKDIR + "/data/skuruppu/{reference}_{sequence}_decompress.tsv"
    shell:
        # """
        # {WORKDIR}/RLZ/rlz -d {WORKDIR}/data/{reference}.fa {WORKDIR}/data/{sequence}.fa
        # """
        " /home/dmakwana/boucher/dmakwana/rlzs/RLZ/rlz -d /home/dmakwana/boucher/dmakwana/rlzs/data/{reference}.fa /home/dmakwana/boucher/dmakwana/rlzs/data/{sequence}.fa "

rule compress_dmak:
    input:
        WORKDIR + "/data/{reference}.fa",
        WORKDIR + "/data/{sequence}.fa"
    output:
        WORKDIR + "/data/{reference}.fmi",
        WORKDIR + "/data/{sequence}.rlz"
    benchmark:
        WORKDIR + "/data/dmakwana/{reference}_{sequence}_compress.tsv"
    shell:
        # """
        # {WORKDIR}/rlz/build/rlz {WORKDIR}/data/{reference}.fa {WORKDIR}/data/{sequence}.fa
        # """
        " /home/dmakwana/boucher/dmakwana/rlzs/rlz/build/rlz /home/dmakwana/boucher/dmakwana/rlzs/data/{reference}.fa /home/dmakwana/boucher/dmakwana/rlzs/data/{sequence}.fa "

rule decompress_dmak:
    input:
        WORKDIR + "/data/{reference}.fmi",
        WORKDIR + "/data/{sequence}.rlz"
    output:
        WORKDIR + "/data/{sequence}_decompressed.fa"
    benchmark:
        WORKDIR + "/data/dmakwana/{reference}_{sequence}_decompress.tsv"
    shell:
        # """
        # {WORKDIR}/rlz/build/rlz -d {WORKDIR}/data/{reference}.fa {WORKDIR}/data/{sequence}.fa
        # """
        " /home/dmakwana/boucher/dmakwana/rlzs/rlz/build/rlz -d /home/dmakwana/boucher/dmakwana/rlzs/data/{reference}.fa /home/dmakwana/boucher/dmakwana/rlzs/data/{sequence}.fa "
