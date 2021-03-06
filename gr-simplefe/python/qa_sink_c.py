#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2019 GPL.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import simplefe_swig as simplefe
from gnuradio import analog

class qa_sink_c (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()
        self.sample_rate=5000000
        self.sink = simplefe.sink_c(self.sample_rate)
        self.sig = analog.sig_source_c(self.sample_rate, analog.GR_COS_WAVE, 150000, 0.99, 0)
        self.tb.connect((self.sig, 0), (self.sink, 0))

        
    def tearDown (self):
        self.tb = None
        self.sink = None

    def test_001_t (self):
        # set up fg
        self.tb.run ()
        # check data

if __name__ == '__main__':
    try:
        gr_unittest.run(qa_sink_c, "qa_sink_c.xml")
    except KeyboardInterrupt:
        print "keyboard exit()"
        
        sys.exit(0)
        
    
