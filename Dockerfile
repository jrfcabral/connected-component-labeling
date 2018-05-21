ARG input_file=../res/100x100.json
FROM ubuntu:18.04

ADD . /adjacent-cells

RUN apt-get update && apt-get -y install libboost-dev libboost-program-options-dev build-essential cmake && mkdir /adjacent-cells/build

WORKDIR /adjacent-cells/build
RUN cmake ..
RUN make -j2

CMD [ "src/adjacent_cells_challenge", $input_file ]