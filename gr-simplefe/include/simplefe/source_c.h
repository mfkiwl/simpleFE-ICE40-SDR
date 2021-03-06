/* -*- c++ -*- */
/* 
 * Copyright 2019 Ning Wang.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_SIMPLEFE_SOURCE_C_H
#define INCLUDED_SIMPLEFE_SOURCE_C_H

#include <simplefe/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace simplefe {

    /*!
     * \brief <+description of block+>
     * \ingroup simplefe
     *
     */
    class SIMPLEFE_API source_c : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<source_c> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of simplefe::source_c.
       *
       * To avoid accidental use of raw pointers, simplefe::source_c's
       * constructor is in a private implementation
       * class. simplefe::source_c::make is the public interface for
       * creating new instances.
       */
      static sptr make(unsigned sample_rate);
    };

  } // namespace simplefe
} // namespace gr

#endif /* INCLUDED_SIMPLEFE_SOURCE_C_H */

